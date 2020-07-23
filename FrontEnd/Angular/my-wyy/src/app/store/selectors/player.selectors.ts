import { PlayState } from "../reducers/player.reducers";
import { createSelector, createFeatureSelector } from '@ngrx/store';

// 这个文件主要是用来得到数据
const selectPlayerStates = (state: PlayState) => state;

// 第一个传入的参数，是用来回调的; 第二个是用来投影的，投影得到对象中的某个属性
export const getPlayer = createFeatureSelector<PlayState>('player');

export const getPlaying = createSelector(selectPlayerStates, (state: PlayState) => state.playing);
export const getPlayList = createSelector(selectPlayerStates, (state: PlayState) => state.playList);
export const getSongList = createSelector(selectPlayerStates, (state: PlayState) => state.songList);
export const getPlayMode = createSelector(selectPlayerStates, (state: PlayState) => state.playMode);
export const getCurrentIndex = createSelector(selectPlayerStates, (state: PlayState) => state.currentIndex);
// 尝试获取属性的组合({}还可以选取两个属性)
export const getCurrentSong = createSelector(selectPlayerStates, ({playList, currentIndex}: PlayState) => playList[currentIndex]);