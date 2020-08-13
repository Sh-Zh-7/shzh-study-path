import { Component, OnInit, Input, Output, EventEmitter } from '@angular/core';
import { SongSheet } from 'src/app/services/data-types/common.types';
import { ActivatedRoute } from '@angular/router';
import { map } from 'rxjs/internal/operators';

@Component({
  selector: 'app-single-sheet',
  templateUrl: './single-sheet.component.html',
  styleUrls: ['./single-sheet.component.less']
})
export class SingleSheetComponent implements OnInit {
  @Input() songSheet: SongSheet;
  @Output() onPlayEmitter = new EventEmitter<number>();

  constructor(private route: ActivatedRoute) {
    this.route.data.pipe(map(res => res.sheetInfo)).subscribe(data => {
      console.log(data);
    })
  }

  ngOnInit(): void {
  }

  onPlay(evt: MouseEvent, id: number) {
    evt.stopPropagation();
    this.onPlayEmitter.emit(id);
  }

  get coverImg(): string {
    return this.songSheet.picUrl || this.songSheet.coverImgUrl;
  }
  
}
