import { Component, OnInit, Input, ViewChild } from '@angular/core';
import { LocalStorageService } from 'src/app/services/local-storage/local-storage.service';
import { USERNAME } from 'src/app/constants/local-storage.namespace';
import { ListComponent } from './list/list.component';

@Component({
  selector: 'app-left-control',
  templateUrl: './left-control.component.html',
  styleUrls: ['./left-control.component.less']
})
export class LeftControlComponent implements OnInit {
  username: string;
  @Input() isCollapsed: boolean;
  @ViewChild(ListComponent) listComponent: ListComponent; 

  constructor(private store: LocalStorageService) { }

  ngOnInit(): void {
    this.username = this.store.get(USERNAME);
  }

  openAddListModal(): void {
    // 在 Angular 中调用子组件
    this.listComponent.openAddListModal();
  } 

}
