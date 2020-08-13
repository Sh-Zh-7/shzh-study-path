import { Component, OnInit } from '@angular/core';
import { SheetParams, SheetList } from 'src/app/services/data-types/common.types';
import { ActivatedRoute, Router } from '@angular/router';
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
  listParams : SheetParams;
  orderValue: 'hot' | 'new' = 'hot';

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private sheetServe: SongSheetService,
  ) {
    this.defaultParam.cat = this.route.snapshot.queryParamMap.get('cat') || '全部';
    this.listParams = this.defaultParam;
    this.getList();
  }

  ngOnInit(): void {
  }

  private getList() {
    this.sheetServe.getPlayList(this.listParams).subscribe(sheet => this.sheet = sheet);
  }

  onChangeOrder(newOrder: 'new' | 'hot') {
    this.listParams.order = newOrder;
    this.listParams.offset = 1;
    this.getList();
  }

  onPageIndexChange(page: number) {
    this.listParams.offset = page;
    console.log(page);
    this.getList();
  }

  onDisplaySingleSong(id: number) {
    this.router.navigate(['sheet-info', id]);
  }

}
