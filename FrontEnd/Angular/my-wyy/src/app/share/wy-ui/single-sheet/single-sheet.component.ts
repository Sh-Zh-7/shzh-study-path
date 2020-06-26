import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { SongSheet } from 'src/app/services/data-types/common.types';

@Component({
  selector: 'app-single-sheet',
  templateUrl: './single-sheet.component.html',
  styleUrls: ['./single-sheet.component.less']
})
export class SingleSheetComponent implements OnInit {
  @Input() songSheet: SongSheet;
  @Output() onPlayEmitter = new EventEmitter<number>();

  constructor() { }

  ngOnInit(): void {
  }

  onPlay(id: number) {
    this.onPlayEmitter.emit(id);
  }

}
