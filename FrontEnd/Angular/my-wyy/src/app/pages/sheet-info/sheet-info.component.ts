import { Component, OnInit } from '@angular/core';
import { SongSheet } from 'src/app/services/data-types/common.types';
import { ActivatedRoute } from '@angular/router';
import { map } from 'rxjs/internal/operators';

@Component({
  selector: 'app-sheet-info',
  templateUrl: './sheet-info.component.html',
  styleUrls: ['./sheet-info.component.less']
})
export class SheetInfoComponent implements OnInit {
  sheetInfo: SongSheet;

  description = {
    long: '',
    short: ''
  }
  controlDesc = {
    isExpand: false,
    label: "展开",
    iconCls: "up"
  }

  constructor(private route: ActivatedRoute) {
    this.route.data.pipe(map(res => res.sheetInfo)).subscribe((sheet: SongSheet) => {
      this.sheetInfo = sheet;
      if (sheet.description) {
        this.getDescription(sheet.description);
      }
    });
  }

  getDescription(rowDescription: string) {
    if (rowDescription.length <= 99) {
      this.description.short = "<b>介绍：</b>" + rowDescription.replace(/\n/g, '<br>');
      this.description.long = "";
    } else {
      this.description.short = "<b>介绍：</b>" + rowDescription.replace(/\n/g, '<br>').slice(0, 99) + "...";
      this.description.long = "<b>介绍：</b>" + rowDescription.replace(/\n/g, '<br>');
    }
  } 

  toggleDesc() {
    this.controlDesc.isExpand = !this.controlDesc.isExpand;
    if (this.controlDesc.isExpand) {
      this.controlDesc.label = "展开";
      this.controlDesc.iconCls = "down";
    } else {
      this.controlDesc.label = "收起";
      this.controlDesc.iconCls = "up";
    }
  }

  ngOnInit(): void {
  }

}
