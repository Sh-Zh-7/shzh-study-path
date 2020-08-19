import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { map } from 'rxjs/internal/operators';
import { MemberService, RecordType } from 'src/app/services/member.service';
import { SongService } from 'src/app/services/song.service';
import { NzMessageService } from 'ng-zorro-antd';
import { Store, select } from '@ngrx/store';
import { AppStoreModule } from 'src/app/store';
import { getCurrentSong, getPlayer } from 'src/app/store/selectors/player.selectors';
import { SongSheetService } from 'src/app/services/song-sheet.service';
import { MemberBatchActionService } from 'src/app/store/member-batch-actions.service';
import { User, recordVal, UserSheet } from 'src/app/services/data-types/member.type';
import { Song } from 'src/app/services/data-types/common.types';
import { findIndex } from 'src/app/utils/array';

@Component({
  selector: 'app-center',
  templateUrl: './center.component.html',
  styleUrls: ['./center.component.less']
})
export class CenterComponent implements OnInit {

  user: User;
  records: recordVal[];
  userSheet: UserSheet;
  recordType = RecordType.weekData;

  private currentSong: Song;
  currentIndex = -1;

  constructor(
    private route: ActivatedRoute,
    private sheetServe: SongSheetService,
    private batchActionsServe: MemberBatchActionService,
    private memberServe: MemberService,
    private songServe: SongService,
    private nzMessageServe: NzMessageService,
    private store$: Store<AppStoreModule>,
  ) {
    this.route.data.pipe(map(res => res.user)).subscribe(([user, userRecord, userSheet]) => {
      this.user = user;
      this.records = userRecord.slice(0, 10);
      this.userSheet = userSheet;
      this.listenCurrentSong();
    });
  }

  ngOnInit(): void {
  }

  private listenCurrentSong() {
    this.store$.pipe(select(getPlayer), select(getCurrentSong)).subscribe(song => {
      this.currentSong = song;
      if (song) {
        const songs = this.records.map(item => item.song);
        this.currentIndex = findIndex(songs, song);
      } else {
        this.currentIndex = -1;
      }
    });
  }

  // onPlaySheet(id: number) {
  //   this.sheetServe.playSheet(id).subscribe(list => {
  //     this.batchActionsServe.selectPlayList({ list, index: 0});
  //   });
  // }

  onChangeType(type: RecordType) {
    if (this.recordType !== type) {
      this.recordType = type;
      this.memberServe.getUserRecord(this.user.profile.userId.toString(), type)
      .subscribe(records => this.records = records.slice(0, 10));
    }
  }

  // onAddSong([song, isPlay]) {
  //   if (!this.currentSong || this.currentSong.id !== song.id) {
  //     this.songServe.getSongList(song)
  //     .subscribe(list => {
  //       if (list.length) {
  //         this.batchActionServe.insertSong(list[0], isPlay);
  //       } else {
  //         this.nzMessageServe.create('warning', '无url!');
  //       }
  //     });
  //   }
  // }
}
