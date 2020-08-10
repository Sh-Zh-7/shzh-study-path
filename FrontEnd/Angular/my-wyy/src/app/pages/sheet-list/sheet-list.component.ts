import { Component, OnInit } from '@angular/core';
import { SheetParams, SheetList } from 'src/app/services/data-types/common.types';
import { ActivatedRoute } from '@angular/router';
import { SongSheetService } from 'src/app/services/song-sheet.service';

@Component({
  selector: 'app-sheet-list',
  templateUrl: './sheet-list.component.html',
  styleUrls: ['./sheet-list.component.less']
})
export class SheetListComponent implements OnInit {
  defaultParam: SheetParams = {
    order: 'hot',
    cat: '全部',
    limit: 35,
    offset: 1
  }
  sheet: SheetList;
  constructor(
    private route: ActivatedRoute,
    private sheetServe: SongSheetService,
  ) {
    this.defaultParam.cat = this.route.snapshot.queryParamMap.get('cat') || '全部';
    this.getList();
  }

  ngOnInit(): void {
  }

  private getList() {
    this.sheetServe.getPlayList(this.defaultParam).subscribe(sheet => this.sheet = sheet)
  }

}
