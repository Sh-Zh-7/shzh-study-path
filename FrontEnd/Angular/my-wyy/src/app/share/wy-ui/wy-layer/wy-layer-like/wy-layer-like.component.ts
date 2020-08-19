import { Component, OnInit, ChangeDetectionStrategy, Input, OnChanges, SimpleChanges } from '@angular/core';
import { SongSheet } from 'src/app/services/data-types/common.types';
import { Store, select } from '@ngrx/store';
import { AppStoreModule } from 'src/app/store';
import { getModal, getLikeId } from 'src/app/store/selectors/member.selectors';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';

@Component({
  selector: 'app-wy-layer-like',
  templateUrl: './wy-layer-like.component.html',
  styleUrls: ['./wy-layer-like.component.less'],
  changeDetection: ChangeDetectionStrategy.OnPush
})
export class WyLayerLikeComponent implements OnInit, OnChanges {
  @Input() mySheets: SongSheet;
  likeId: string;
  formModel: FormGroup;
  creating = false;

  constructor(
    private store$: Store<AppStoreModule>,
    private fb: FormBuilder
  ) {
    this.store$.pipe(select(getModal), select(getLikeId)).subscribe(likeId => console.log(likeId));
    this.formModel = this.fb.group({
      sheetName: ['', [Validators.required]]
    });
  }
  ngOnChanges(changes: SimpleChanges): void {
    console.log(changes.mySheets.currentValue);
  }

  ngOnInit(): void {
  }

  onSubmit() {

  }
}
