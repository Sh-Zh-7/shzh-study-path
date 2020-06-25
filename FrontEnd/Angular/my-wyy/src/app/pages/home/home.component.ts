import { Component, OnInit, ViewChild } from '@angular/core';
import { Banner,SongSheet, HotTag, Singer } from 'src/app/services/data-types/common.types';
import { NzCarouselComponent } from 'ng-zorro-antd';
import { ActivatedRoute } from '@angular/router';
import { map } from 'rxjs/internal/operators';

@Component({
  selector: 'app-home',
  templateUrl: './home.component.html',
  styleUrls: ['./home.component.less']
})
export class HomeComponent implements OnInit {
  @ViewChild(NzCarouselComponent, {static: true}) private carousel: NzCarouselComponent; 
  curIndex: number = 0;

  banners: Banner[];
  hotTags: HotTag[];
  songSheet: SongSheet[];
  singers: Singer[];

  constructor(
    private route: ActivatedRoute
  ) {
    this.route.data.pipe(map(res => res.homeDatas)).subscribe(([banners, hotTags, songSheet, singers]) => {
      this.banners = banners;
      this.hotTags = hotTags;
      this.songSheet = songSheet;
      this.singers = singers;
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

}
