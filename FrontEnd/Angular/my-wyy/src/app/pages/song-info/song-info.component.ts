import { Component, OnInit} from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { map } from 'rxjs/internal/operators';
import { Song, Lyric } from 'src/app/services/data-types/common.types';
import { WyLyric, BaseLyricLine } from 'src/app/share/wy-ui/wy-player/wy-player-panel/wy-lyric';

@Component({
  selector: 'app-song-info',
  templateUrl: './song-info.component.html',
  styleUrls: ['./song-info.component.less']
})
export class SongInfoComponent implements OnInit {
  song: Song;
  lyric: BaseLyricLine[];

  controlLyric = {
    isExpand: false,
    label: '展开',
    iconCls: 'up'
  };

  constructor(
    private route: ActivatedRoute
  ) {
    this.route.data.pipe(map(res => res.songInfo)).subscribe(([song, lyric]) => {
        this.song = song;
        this.lyric = new WyLyric(lyric).lines;
    });
  }

  ngOnInit(): void {
  }

  toggleLyric() {
    this.controlLyric.isExpand = !this.controlLyric.isExpand;
    if (this.controlLyric.isExpand) {
      this.controlLyric.label = '展开';
      this.controlLyric.iconCls = 'down';
    } else {
      this.controlLyric.label = '收起';
      this.controlLyric.iconCls = 'up';
    }
  }

}
