import { Component, OnInit, Input, TemplateRef, Output, EventEmitter, ViewChild, ElementRef, AfterViewInit, ViewContainerRef, OnChanges, SimpleChanges } from '@angular/core';
import { fromEvent } from 'rxjs';
import { pluck, debounceTime, distinctUntilChanged } from 'rxjs/internal/operators';
import { SearchResult } from 'src/app/services/data-types/common.types';
import { IsEmptyObj } from 'src/app/utils/tools';
import { Overlay, OverlayRef } from '@angular/cdk/overlay';
import { ComponentPortal } from '@angular/cdk/portal';
import { WySearchPanelComponent } from './wy-search-panel/wy-search-panel.component';

@Component({
  selector: 'app-wy-search',
  templateUrl: './wy-search.component.html',
  styleUrls: ['./wy-search.component.less']
})
export class WySearchComponent implements OnInit, AfterViewInit, OnChanges {
  @Input() customView: TemplateRef<any>;
  @Input() searchResult: SearchResult;
  @Input() connectedRef: ElementRef;  // 让用户可以自己传入ElementRef
  @Output() onSearch: EventEmitter<string> = new EventEmitter<string>();
  @ViewChild('nzInput', {static: false}) private nzInput: ElementRef;
  @ViewChild('search', {static: false}) private defalutRef: ElementRef;

  private overlayRef: OverlayRef;

  constructor(
    private overlay: Overlay,
    private viewContainerRef: ViewContainerRef,
  ) { }

  ngOnInit(): void { }

  ngOnChanges(changes: SimpleChanges): void {
    if (changes['searchResult'] && !changes['searchResult'].firstChange) {
      if (!IsEmptyObj(this.searchResult)) {
        this.showOverlayPanel();
      }
    }
  }

  ngAfterViewInit(): void {
    // 利用debounceTime和distincUntilChanged进行节流
    fromEvent(this.nzInput.nativeElement, 'input')
      .pipe(debounceTime(300), distinctUntilChanged(), pluck('target', 'value'))
      .subscribe((value: string) => {
        if (value) {
          this.onSearch.emit(value);
        } else {
          this.searchResult = {};
          this.hideOverlayPanel();
        }
      });
  }

  onFocus() {
    if (this.searchResult && !IsEmptyObj(this.searchResult)) {
      this.showOverlayPanel();
    }
  }

  showOverlayPanel() {
    this.hideOverlayPanel();
    const positionStrategy = this.overlay.position()
      .flexibleConnectedTo(this.connectedRef || this.defalutRef)
      .withPositions([{
        originX: 'start',
        originY: 'bottom',
        overlayX: 'start',
        overlayY: 'top'
      }]).withLockedPosition(true);

    this.overlayRef = this.overlay.create({
      hasBackdrop: true,
      positionStrategy: positionStrategy,
      scrollStrategy: this.overlay.scrollStrategies.reposition()
    });
    const panelPortal = new ComponentPortal(WySearchPanelComponent, this.viewContainerRef);
    const panelRef = this.overlayRef.attach(panelPortal);
    panelRef.instance.searchResult = this.searchResult;
    this.overlayRef.backdropClick().subscribe(() => {
      this.hideOverlayPanel();
    });
  }

  hideOverlayPanel() {
    if (this.overlayRef && this.overlayRef.hasAttached()) {
      this.overlayRef.dispose();
      console.log('dispose!');
    }
  }

}
