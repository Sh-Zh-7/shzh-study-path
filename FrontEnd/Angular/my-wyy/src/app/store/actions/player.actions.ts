import { createAction, props } from '@ngrx/store';
import { Song } from 'src/app/services/data-types/common.types';
import { PlayMode } from 'src/app/share/wy-ui/wy-player/wy-player.type';

// 这个文件主要是用来改变数据
// CreateAction函数的第一个参数是用来提示和防止重复的, 可以在Redux中看到
// 第二个参数是metadata
export const SetPlaying = createAction('[player] Set playing', props<{ playing: boolean}>());
export const SetPlayList = createAction('[player] Set playing list', props<{ playList: Song[]}>());
export const SetSongList = createAction('[player] Set song list', props<{ songList: Song[]}>());
export const SetPlayMode = createAction('[player] Set playing mode', props<{ playMode: PlayMode}>());
export const SetCurrentIndex = createAction('[player] Set current index', props<{ currentIndex: number}>());
