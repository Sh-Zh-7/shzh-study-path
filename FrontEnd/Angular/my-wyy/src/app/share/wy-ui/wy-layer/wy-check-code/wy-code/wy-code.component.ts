import { Component, OnInit, ChangeDetectionStrategy, forwardRef, AfterViewInit, ViewChild, ElementRef, OnDestroy, ChangeDetectorRef } from '@angular/core';
import { NG_VALUE_ACCESSOR, ControlValueAccessor } from '@angular/forms';
import { fromEvent, Subject } from 'rxjs';
import { takeUntil } from 'rxjs/internal/operators';
import { BACKSPACE } from '@angular/cdk/keycodes';

const CODELEN = 4;

@Component({
  selector: 'app-wy-code',
  templateUrl: './wy-code.component.html',
  styleUrls: ['./wy-code.component.less'],
  changeDetection: ChangeDetectionStrategy.OnPush,
  providers: [{
    provide: NG_VALUE_ACCESSOR,
    useExisting: forwardRef(() => WyCodeComponent),
    multi: true
  }]
})
export class WyCodeComponent implements OnInit, ControlValueAccessor, AfterViewInit, OnDestroy {

  constructor(private cdr: ChangeDetectorRef) {
    this.inputArr = Array(CODELEN).fill('');
  }

  inputArr: string[];
  private code = '';
  private inputItems: HTMLElement[];
  private destroy$ = new Subject();

  result: string[] = [];
  currentFocusIndex = 0;

  @ViewChild('codeWrap', {static: true}) private elementRef: ElementRef;
  private onChange: any = (code: string) => {};
  private onTouched: any = () => {};
  ngOnDestroy(): void {
    this.destroy$.next();
    this.destroy$.complete();
  }

  ngAfterViewInit(): void {
    this.inputItems = this.elementRef.nativeElement.getElementsByClassName('item') as HTMLElement[];
    this.inputItems[0].focus();
    for (let i = 0; i < this.inputItems.length; ++i) {
      const item = this.inputItems[i];
      fromEvent(item, 'keyup').pipe(takeUntil(this.destroy$)).subscribe((event: KeyboardEvent) => this.listenup(event));
      fromEvent(item, 'click').pipe(takeUntil(this.destroy$)).subscribe(() => this.currentFocusIndex = i);
    }
  }

  listenup(event: KeyboardEvent) {
    const target = event.target as HTMLInputElement;
    const value = target.value;
    const isBackSpace = event.keyCode === BACKSPACE;
    if (/\D/.test(value)) {
      target.value = '';
      this.result[this.currentFocusIndex] = '';
    } else if (value) {
      this.result[this.currentFocusIndex] = value;
      this.currentFocusIndex = (this.currentFocusIndex + 1) % CODELEN;
      this.inputItems[this.currentFocusIndex].focus();
    } else if (isBackSpace) {
      this.result[this.currentFocusIndex] = '';
      this.currentFocusIndex = Math.max(this.currentFocusIndex - 1, 0);
      this.inputItems[this.currentFocusIndex].focus();
    }
    this.checkResult(this.result);
  }

  private checkResult(result: string[]) {
    const codeStr = result.join('');
    this.setValue(codeStr);
  }

  setValue(code: string) {
    this.code = code;
    this.onChange(code);
    this.cdr.markForCheck();
  }

  writeValue(code: string): void {
    this.setValue(code);
  }
  registerOnChange(fn: any): void {
    this.onChange = fn;
  }
  registerOnTouched(fn: any): void {
    this.onTouched = fn;
  }

  ngOnInit(): void {
  }

}
