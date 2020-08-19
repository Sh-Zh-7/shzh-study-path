import { Song } from '../services/data-types/common.types';

export function inArray(arr: any[], target: any) {
  return arr.indexOf(target) != -1;
}

export function findIndex(list: Song[], currentSong: Song): number {
  return list.findIndex(item => item.id === currentSong.id);
}
