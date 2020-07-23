import { Component, OnInit, ViewEncapsulation, ViewChild, ElementRef, ChangeDetectionStrategy, Input, Inject, ChangeDetectorRef, OnDestroy, forwardRef, Output, EventEmitter } from '@angular/core';
import { SliderEventObserverConfig, SliderValue } from './wy-slider.types';
import { fromEvent, merge, Observable, Subscription } from 'rxjs';
import { DOCUMENT } from '@angular/common';
import { sliderEvent, getElementOffset } from './wy-slider-help';
import { pluck, filter, tap, map, distinctUntilChanged, takeUntil } from 'rxjs/internal/operators';
import { inArray } from 'src/app/utils/array';
import { limitNumberInRange, getPercent } from 'src/app/utils/number';
import { ControlValueAccessor, NG_VALUE_ACCESSOR } from '@angular/forms';

@Component({
  selector: 'app-wy-slider',
  templateUrl: './wy-slider.component.html',
  styleUrls: ['./wy-slider.component.less'],
  encapsulation: ViewEncapsulation.None,
  // 虽然不知道为什么这里要改为OnPush，但是还是这样改好了
  changeDetection: ChangeDetectionStrategy.OnPush,
  providers: [{
    provide: NG_VALUE_ACCESSOR,
    useExisting: forwardRef(() => WySliderComponent),
    multi: true
  }]
})
export class WySliderComponent implements OnInit, OnDestroy, ControlValueAccessor {
  // Input
  @Input() wyVertical = false;
  @Input() wyMin = 0;
  @Input() wyMax = 100;
  @Input() bufferOffset: SliderValue = 0;

  @Output() wyOnAfterChange = new EventEmitter<SliderValue>();
  // DOM
  @ViewChild("wySlider", {static: true}) private wySilder: ElementRef;
  private sliderDOM: HTMLDivElement;

  // Observable and subscription
  dragStart$: Observable<number>;
  dragMove$: Observable<number>;
  dragEnd$: Observable<Event>;
  dragStart_: Subscription | null;
  dragMove_: Subscription | null;
  dragEnd_: Subscription | null;

  // ControlValueAccessor interface functions
  private onValueChange(value: SliderValue): void {}
  private onTouched(): void {}

  // Others
  isDragging: boolean = false;
  value: SliderValue = null;
  offset: SliderValue = null;

  constructor(
    @Inject(DOCUMENT) private doc: Document,
    private cdr: ChangeDetectorRef,  
  ) { }

  // fn这个函数是被传进来的
  // 要做的仅仅是把fn保存就行了
  writeValue(value: SliderValue): void {
    this.setValue(value);
  }
  registerOnChange(fn: (value: SliderValue) => void): void {
    this.onValueChange = fn;
  }
  registerOnTouched(fn: () => void): void {
    this.onTouched = fn;
  }

  ngOnDestroy(): void {
    this.unsubscribeDrag();
  }

  ngOnInit(): void {
    // 赋值HTMLDivElement
    this.sliderDOM = this.wySilder.nativeElement;

    // 在初始化的时候给元素绑定事件
    this.createDraggingObservables();
    this.subscribeDrag(['start']);
  }

  createDraggingObservables() {
    // 定义并绑定事件(绑定元素利用了DOMCUMENT这个TOKEN进行DI)
    // 利用fromEvent获得的Observable的主要目的，就是通过触发事件获得自己想要的数据
    const orientField = this.wyVertical? 'pageY': 'pageX';
    // 绑定两套事件
    const mouse: SliderEventObserverConfig = {
      start: 'mousedown',
      move: 'mousemove',
      end: 'mouseup',
      filterFunc: (e: MouseEvent) => e instanceof MouseEvent,
      pluckKey: [orientField] 
    };
    const touch: SliderEventObserverConfig = {
      start: 'touchstart',
      move: 'touchmove',
      end: 'touchend',
      filterFunc: (e: TouchEvent) => e instanceof TouchEvent,
      pluckKey: ['touches', '0', orientField]
    };

    // 给mouse和touch两个对象绑定三种事件的subscribe
    [mouse, touch].forEach(source => {
      const {start, move, end, filterFunc, pluckKey} = source;

      source.startPlucked$ = fromEvent(this.sliderDOM, start)
      .pipe(
        filter(filterFunc),
        tap(sliderEvent),
        pluck(...pluckKey),
        map((position: number) => this.findClosestValue(position))
      );

      source.end$ = fromEvent(this.doc, end);
      source.moveResolved$ = fromEvent(this.doc, move)
      .pipe(
        filter(filterFunc),
        tap(sliderEvent),
        pluck(...pluckKey),
        distinctUntilChanged(),
        map((position: number) => this.findClosestValue(position)),
        takeUntil(source.end$)
      );
    })
    this.dragStart$ = merge(mouse.startPlucked$, touch.startPlucked$);
    this.dragMove$ = merge(mouse.moveResolved$, touch.moveResolved$);
    this.dragEnd$ = merge(mouse.end$, touch.end$);
  }

  private subscribeDrag(events: string[] = ['start', 'move', 'end']) {
    if (inArray(events, 'start') && this.dragStart$ && !this.dragStart_) {
      this.dragStart$.subscribe(this.onDragStart.bind(this));
    }
    if (inArray(events, 'move') && this.dragMove$ && !this.dragMove_) {
      this.dragMove$.subscribe(this.onDragMove.bind(this));
    }
    if (inArray(events, 'end') && this.dragEnd$ && !this.dragEnd_) {
      this.dragEnd$.subscribe(this.onDragEnd.bind(this));
    }
  }

  private unsubscribeDrag(events: string[] = ['start', 'move', 'end']) {
    if (inArray(events, 'start') && this.dragStart_) {
      this.dragStart_.unsubscribe();
      this.dragStart_ = null;
    }
    if (inArray(events, 'move') && this.dragMove_) {
      this.dragMove_.unsubscribe();
      this.dragMove_ = null;
    }
    if (inArray(events, 'end') && this.dragEnd_) {
      this.dragEnd_.unsubscribe();
      this.dragEnd_ = null;
    }
  }

  private onDragStart(value: number) {
    this.toggleDragMoving(true);
    this.setValue(value);
  }
  private onDragMove(value: number) {
    if (this.isDragging) {
      this.setValue(value);
      this.cdr.markForCheck();
    }
  }
  private onDragEnd() {
    this.wyOnAfterChange.emit(this.value);
    this.toggleDragMoving(false);
    this.cdr.markForCheck();
  }

  private setValue(value: SliderValue) {
    if (!this.valuesEqual(this.value, value)) {
      this.value = value;
      this.updateTrackAndHandles();
      // 反过来修改UI的value
      this.onValueChange(value);
    }
  }

  // 这个函数主要是用来判断value是否合法
  private assertValueValid(value: SliderValue): boolean {
    return isNaN(typeof value !== 'number'? parseFloat(value): value);
  }

  private valuesEqual(valA: SliderValue, valB: SliderValue) {
    if (typeof valA !== typeof valB) {
      return false;
    }
    return valA === valB;
  }

  private updateTrackAndHandles() {
    this.offset = this.getValueToOffset(this.value);
    this.cdr.markForCheck();
  }

  private toggleDragMoving(flag: boolean) {
    this.isDragging = flag;
    if (this.isDragging) {
      this.subscribeDrag(['move', 'end']);
    } else {
      this.unsubscribeDrag(['move', 'end']);
    }
  }

  private getValueToOffset(value: SliderValue): SliderValue {
    return getPercent(this.wyMin, this.wyMax, value);
  }

  private findClosestValue(position: number): number {
    // 获取滑块总长
    const sliderLength = this.getSliderLength();

    // 滑块(左, 上)端点位置
    const sliderStart = this.getSliderStartPosition();

    // 滑块当前位置 / 滑块总长
    const ratio = limitNumberInRange((position - sliderStart) / sliderLength, 0, 1);
    const ratioTrue = this.wyVertical ? 1 - ratio : ratio;
    return ratioTrue * (this.wyMax - this.wyMin) + this.wyMin;
  }


  private getSliderLength(): number {
    return this.wyVertical ? this.sliderDOM.clientHeight : this.sliderDOM.clientWidth;
  }

  private getSliderStartPosition(): number {
    const offset = getElementOffset(this.sliderDOM);
    return this.wyVertical ? offset.top : offset.left;
  }

}
