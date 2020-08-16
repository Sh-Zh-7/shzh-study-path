import { Component, OnInit, ChangeDetectionStrategy, ElementRef, ChangeDetectorRef, Renderer2, ViewChild } from '@angular/core';
import { Store, select } from '@ngrx/store';
import { AppStoreModule } from 'src/app/store';
import { getModalType, getModalVisiable, getModal } from 'src/app/store/selectors/member.selectors';
import { ModalType } from 'src/app/store/reducers/member.reducers';
import { Overlay, OverlayRef, OverlayKeyboardDispatcher, BlockScrollStrategy, OverlayContainer } from '@angular/cdk/overlay';
import { ESCAPE } from '@angular/cdk/keycodes';
import { MemberBatchActionService } from 'src/app/store/member-batch-actions.service';
import { getWindowSize, getHideDomSize } from 'src/app/utils/dom';
import { trigger, state, style, animate, transition } from '@angular/animations';

@Component({
  selector: 'app-wy-layer-modal',
  templateUrl: './wy-layer-modal.component.html',
  styleUrls: ['./wy-layer-modal.component.less'],
  changeDetection: ChangeDetectionStrategy.OnPush,
  animations: [trigger("showHide", [
    state('show', style({ transform: 'scale(1)', opacity: 1 })),
    state('hide', style({ transform: 'scale(0)', opacity: 0})),
    transition('show<=>hide', animate('0.2s'))
  ])]
})
export class WyLayerModalComponent implements OnInit {
  showModal = 'hide';
  modalType: ModalType = ModalType.Default;
  private visiable: boolean = false;
  private overlayRef: OverlayRef;
  private scrollStrategy: BlockScrollStrategy;
  private overlayContainerEl: HTMLElement;
  @ViewChild('modalContainer', { static: false }) private modalRef: ElementRef;
  private resizeHandler: () => void;

  constructor(
    private store$: Store<AppStoreModule>,
    private overlay: Overlay,
    private elementRef: ElementRef,
    private cdr: ChangeDetectorRef,
    private overlayKeyboardDispatcher: OverlayKeyboardDispatcher,
    private batchActionService: MemberBatchActionService,
    private rd: Renderer2,
    private overlayContainerServe: OverlayContainer
  ) {
    const appStore$ = this.store$.pipe(select(getModal));
    appStore$.pipe(select(getModalType)).subscribe(type => this.watchModalType(type))
    appStore$.pipe(select(getModalVisiable)).subscribe(visiable => this.watchModalVisiable(visiable))
    this.scrollStrategy = this.overlay.scrollStrategies.block();
  }

  ngOnInit(): void {
    this.overlayContainerEl = this.overlayContainerServe.getContainerElement();
    this.createOverlay();
  }

  onClick() {
    // 一定要利用batchAction, 不然this.visiable无法改变！
    this.batchActionService.controlModal(false, this.modalType);
  }

  private changePointerEvents(type: 'none' | 'auto') {
    if (this.overlayContainerEl) {
      this.overlayContainerEl.style.pointerEvents = type;
    }
  }

  private keepCenter(modal: HTMLElement, size: { w: number, h: number}) {
    const windowSize = getWindowSize();
    const left = (windowSize.w - size.w) / 2;
    const top = (windowSize.h - size.h) / 2;
    modal.style.left = left + 'px';
    modal.style.top = top + 'px';
  }

  private createOverlay() {
    this.overlayRef = this.overlay.create();
    this.overlayRef.overlayElement.appendChild(this.elementRef.nativeElement);
    this.overlayRef.keydownEvents().subscribe(e => this.handleKeyDownEvent(e));
  }

  private handleKeyDownEvent(evt: KeyboardEvent) {
    if (evt.keyCode === ESCAPE) {
      this.onClick();
    }
  }

  private listenResizeToCenter() {
    const modal = this.modalRef.nativeElement;
    const modalSize = getHideDomSize(modal);
    this.keepCenter(modal, modalSize);
    this.resizeHandler = this.rd.listen('window', 'resize', () => this.keepCenter(modal, modalSize));
  }

  private watchModalVisiable(visiable: boolean) {
    if (visiable !== this.visiable) {
      this.visiable = visiable;
      this.handleVisiableChange(visiable);
    }
  }

  private watchModalType(type) {
    if (type !== this.modalType) {
      this.modalType = type;
      this.cdr.markForCheck();
    }
  }

  private handleVisiableChange(visiable) {
    if (visiable) {
      this.showModal = 'show';
      this.scrollStrategy.enable();
      this.overlayKeyboardDispatcher.add(this.overlayRef);
      // 监听
      this.listenResizeToCenter();
      this.changePointerEvents('auto')
    } else {
      this.showModal = 'hide';
      this.scrollStrategy.disable();
      this.overlayKeyboardDispatcher.remove(this.overlayRef);
      // 取消监听
      this.resizeHandler();
      this.changePointerEvents('none');
    }
    this.cdr.markForCheck();
  }

}
