import { PlayMode } from 'src/app/share/wy-ui/wy-player/wy-player.type';
import { Song } from 'src/app/services/data-types/common.types';
import { createReducer, on, Action } from '@ngrx/store';
import { SetPlaying, SetPlayList, SetSongList, SetPlayMode, SetCurrentIndex } from '../actions/player.actions';

export interface PlayState {
  // 播放状态
  playing: boolean;
  // 播放模式
  playMode: PlayMode;
  // 歌曲列表
  playList: Song[];
  // 播放列表
  songList: Song[];
  // 当前正在播放的索引
  currentIndex: number;
}

export const initialState: PlayState = {
  playing: false,
  playMode: { type: 'loop', label: '单曲循环' },
  playList: [],
  songList: [],
  currentIndex: -1,
};

// 返回一个类啊
// 使用的时候不用传递state参数，他会自动调用当前的state
const reducer = createReducer(
  initialState,
  // 这里的必须得和PlayState中的属性一致
  on(SetPlaying, (state, { playing }) => ({...state, playing})),
  on(SetPlayList, (state, { playList }) => ({...state, playList})),
  on(SetSongList, (state, { songList }) => ({...state, songList})),
  on(SetPlayMode, (state, { playMode }) => ({...state, playMode})),
  on(SetCurrentIndex, (state, { currentIndex }) => ({...state, currentIndex}))
);

export function playerReducer(state: PlayState, action: Action) {
  return reducer(state, action);
}

