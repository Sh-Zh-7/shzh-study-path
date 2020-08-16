import { Component, OnInit, ViewChild } from '@angular/core';
import { Banner,SongSheet, HotTag, Singer } from 'src/app/services/data-types/common.types';
import { NzCarouselComponent } from 'ng-zorro-antd';
import { ActivatedRoute, Router } from '@angular/router';
import { map } from 'rxjs/internal/operators';
import { SongSheetService } from 'src/app/services/song-sheet.service';
import { Store, select } from '@ngrx/store';
import { AppStoreModule } from 'src/app/store';
import { SetSongList, SetPlayList, SetCurrentIndex } from 'src/app/store/actions/player.actions';
import { getUserId, getModal } from 'src/app/store/selectors/member.selectors';
import { MemberService } from 'src/app/services/member.service';
import { User } from 'src/app/services/data-types/member.type';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.less']
})
export class HomeComponent implements OnInit {
  @ViewChild(NzCarouselComponent, {static: true}) private carousel: NzCarouselComponent; 
  curIndex: number = 0;

  userId: string;
  user: User;

  banners: Banner[];
  hotTags: HotTag[];
  songSheet: SongSheet[];
  singers: Singer[];

  constructor(
    private route: ActivatedRoute,
    private router: Router,
    private songSheetService: SongSheetService,
    private memberService: MemberService,
    private store$: Store<AppStoreModule>
  ) {
    this.route.data.pipe(map(res => res.homeDatas)).subscribe(([banners, hotTags, songSheet, singers]) => {
      this.banners = banners;
      this.hotTags = hotTags;
      this.songSheet = songSheet;
      this.singers = singers;
    });

    this.store$.pipe(select(getModal), select(getUserId)).subscribe(userId => {
      if (userId) {
        this.userId = userId;
        this.memberService.getUserDetail(userId).subscribe(user => this.user = user);
      } else {
        this.userId = "";
        this.user = null;
      }
      
    });
   }

  ngOnInit(): void {
  }

  onBeforeChange({to}) {
    this.curIndex = to;
  }

  onSlideChange(changeType: "pre" | "next") {
    this.carousel[changeType]();
  }

  onPlay(id: number) {
    this.songSheetService.playSheet(id).subscribe(result => {
      this.store$.dispatch(SetSongList({ songList: result}));
      this.store$.dispatch(SetPlayList({ playList: result}));
      this.store$.dispatch(SetCurrentIndex({ currentIndex: 0 }));
    })
  }

  onDisplaySingleSong(id: number) {
    this.router.navigate(["/sheet-info", id]);
  }
}
