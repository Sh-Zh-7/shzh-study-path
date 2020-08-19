import { Component, OnInit, ChangeDetectionStrategy, Input, Output, EventEmitter } from '@angular/core';
import { recordVal } from '../../../../services/data-types/member.type';
import { RecordType } from '../../../../services/member.service';
import { Song } from 'src/app/services/data-types/common.types';
import { MemberBatchActionService } from 'src/app/store/member-batch-actions.service';
import { ModalType } from 'src/app/store/reducers/member.reducers';
import { AppStoreModule } from 'src/app/store';
import { Store } from '@ngrx/store';
import { SetModalType, SetLikeSongId } from 'src/app/store/actions/member.actions';

@Component({
  selector: 'app-records',
  templateUrl: './records.component.html',
  styleUrls: ['./records.component.less'],
  changeDetection: ChangeDetectionStrategy.OnPush
})
export class RecordsComponent implements OnInit {
  @Input() records: recordVal[];
  @Input() recordType = RecordType.weekData;
  @Input() listenSongs = 0;
  @Input() currentIndex = -1;

  @Output() onChangeType = new EventEmitter<RecordType>();
  @Output() onAddSong = new EventEmitter<[Song, boolean]>();
  constructor(private store$: Store<AppStoreModule>) {
  }

  ngOnInit() {
  }

  onLike(song: Song) {
    this.store$.dispatch(SetModalType({modalType: ModalType.Like}));
    this.store$.dispatch(SetLikeSongId({likeId: song.id.toString()}));
  }

}
