import { Component, OnInit, Input, OnChanges, SimpleChanges } from '@angular/core';
import { TrackStyle } from './wy-slider.types';

@Component({
  selector: 'app-wy-slider-track',
  template: '<div class="wy-slider-track" [class.buffer]="wyBuffer" [ngStyle]="style"></div>',
})
export class WySliderTrackComponent implements OnInit, OnChanges {
  @Input() wyVertical = false;
  @Input() wyLength : number;
  @Input() wyBuffer = false;
  style: TrackStyle = {}

  constructor() { }
  ngOnChanges(changes: SimpleChanges): void {
    if (changes['wyLength']) {
      if (this.wyVertical) {
        this.style.height = this.wyLength + "%";
        this.style.left = null;
        this.style.width = null;
      } else {
        this.style.width = this.wyLength + "%";
        this.style.bottom = null;
        this.style.height = null;
      }
    }
  }

  ngOnInit(): void { }

}
