import { Component, OnInit, ViewChild, ElementRef, Inject } from '@angular/core';
import { AppStoreModule } from 'src/app/store';
import { Store, select } from '@ngrx/store';
import { getPlayer, getSongList, getPlayList, getCurrentIndex, getPlayMode, getCurrentSong } from 'src/app/store/selectors/player.selectors';
import { Song } from 'src/app/services/data-types/common.types';
import { PlayMode } from './wy-player.type';
import { SetCurrentIndex } from 'src/app/store/actions/player.actions';
import { DOCUMENT } from '@angular/common';
import { Subscription, fromEvent } from 'rxjs';
import { trigger, state, style, transition, animate } from '@angular/animations';

@Component({
  selector: 'app-wy-player',
  templateUrl: './wy-player.component.html',
  styleUrls: ['./wy-player.component.less'],
  animations: [trigger('showHide', [
    state('show', style({bottom: 0})),
    state('hide', style({bottom: -71})),
    transition('show=>hide', [animate('0.3s')]),
    transition('hide=>show', [animate('0.1s')])
  ])]
})
export class WyPlayerComponent implements OnInit {
  playing: boolean;
  playMode: PlayMode;
  songList: Song[];
  playList: Song[];
  currentIndex: number;
  currentSong: Song;

  showPlayer: string;
  isAnimation: boolean;
  isLocked: boolean;

  // 这里一定要加static: true， 不然在ngOnInit上根本就检测不出来
  @ViewChild('audio', {static: true}) private audio: ElementRef;
  private audioEl: HTMLAudioElement;

  percent = 0;
  bufferOffset = 0;

  volumn: number = 70;
  currentTime: number = 0;
  canPlay: boolean = false; // 能不能播放，比如一开始没有歌曲的时候就不能播放

  // 点击其它地方隐藏音量组件
  showVolumnPanel: boolean = false;
  selfClick: boolean = false;
  private winClick: Subscription;

  showPanel: boolean = false;

  constructor(
    private store$: Store<AppStoreModule>,
    @Inject(DOCUMENT) private doc: Document
  ) { 
    const appStore$ = this.store$.pipe(select(getPlayer));
    appStore$.pipe(select(getSongList)).subscribe(list => this.watchList(list, 'songList'));
    appStore$.pipe(select(getPlayList)).subscribe(list => this.watchList(list, 'playList'));
    appStore$.pipe(select(getCurrentIndex)).subscribe(index => this.watchCurrentIndex(index));
    appStore$.pipe(select(getPlayMode)).subscribe(mode => this.watchPlayMode(mode));
    appStore$.pipe(select(getCurrentSong)).subscribe(song => this.watchCurrentSong(song));
  }

  ngOnInit(): void {
    this.audioEl = this.audio.nativeElement;
  }

  watchList(list, type) {
    this[type] = list;
  }

  watchPlayMode(mode) {
    this.playMode = mode;
  }

  watchCurrentIndex(index: number) {
    this.currentIndex = index;
  }

  watchPlaying(playing) {
    this.playing = playing;
  }

  watchCurrentSong(song) {
    this.currentSong = song;
  }

  onCanPlay() {
    this.play();
  }

  onPrev(index) {
    if (this.canPlay) {
      const newIndex = index < 0? this.songList.length - 1: index;
      this.updateIndex(newIndex);
    }
  }

  onNext(index) {
    if (this.canPlay) {
      const newIndex = 
        index >= this.songList.length?  0 : index;
      this.updateIndex(newIndex);
    }
  }

  updateIndex(index) {
    this.store$.dispatch(SetCurrentIndex({ currentIndex: index }));
    this.canPlay = false;
  }

  updateSong(song: Song, songList: Song[]) {
    const index = songList.findIndex(item => item.id === song.id);
    this.store$.dispatch(SetCurrentIndex({currentIndex: index}));
  }

  onToggle() {
    if (this.canPlay) {
      if (this.playing) {
        this.audioEl.pause();
      } else {
        this.audioEl.play();
      }
      this.playing = !this.playing;
    }
  }

  onPercentChange(per: number) {
    this.audioEl.currentTime = this.totalTime * (per / 100)
  }

  onVolumnChange(per: number) {
    this.audioEl.volume = per / 100;
  }

  onTogglePanel() {
    this.onToggleAll('showPanel');
  }

  onToggleVolumn() {
    this.onToggleAll('showVolumnPanel');
  }

  onToggleAll(property: string) {
    this[property] = !this[property];
    // 如果显示了，就**观察**是否点击了窗口
    if (this[property]) {
      this.bindDocumentClickListner();
    } else {
      this.unbindDocumentClickListner();
    }
  }

  bindDocumentClickListner() {
    this.winClick = fromEvent(this.doc, "click").subscribe(() => {
      // 其实播放组件也是包含在你DOM下面的
      if (!this.selfClick) {
        this.showPanel = false;
        this.showVolumnPanel = false;
        this.unbindDocumentClickListner();
      }
      // 为什么这里要设置为false, 因为事件是有优先级的
      // 如果是点击播放组件的话，在这之前selfClick的值是true, 但是同样也会触发DOM的click，所以最终还是false
      // 同样，如果这里不设置false的话，第一次点击图标后就是true, 然后就永远进不去那个if了
      this.selfClick = false;
    })
  }

  unbindDocumentClickListner() {
    if (this.winClick) {
      this.winClick.unsubscribe();
      this.winClick = null;
    }
  }

  onTimeUpdate(e: Event) {
    this.currentTime= (e.target as HTMLAudioElement).currentTime;
    this.percent = this.currentTime / this.totalTime * 100;
    const buffer = this.audioEl.buffered;
    if (buffer.length && this.bufferOffset < 100) {
      this.bufferOffset = buffer.end(0) / this.totalTime * 100;
    }
  }

  private play() {
    this.canPlay = true;
    this.playing = true;
    this.audioEl.play();
  }

  // 这个get accessor不用专门再次定义属性了
  get picUrl() {
    return this.currentSong? this.currentSong.al.picUrl :
     "//s4.music.126.net/style/web2/img/default/default_album.jpg";
  }

  get totalTime() {
    if (this.currentSong) {
      return this.currentSong.dt / 1000;
    } else {
      return 0;
    }
  }

  setPlayer(state: string) {
    if (!this.isAnimation && !this.isLocked) {
      this.showPlayer = state;
    }
  }

}
