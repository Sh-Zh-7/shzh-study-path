export interface AnyJson {
  [key: string]: any;
}

export interface Banner {
  targetId: number;
  url: string;
  imageUrl: string;
}

export interface HotTag {
  id: number;
  name: string;
  position: number;
}

export interface Singer {
  id: number;
  name: string;
  alias: string[];
  picUrl: string;
  albumSize: number;
}

export interface Song {
  id: number;
  name: string;
  url: string;
  ar: Singer[];
  al: { id: number; name: string; picUrl: string };
  dt: number;
}

export interface SongUrl {
  id: number;
  url: string;
}

export interface SongSheet {
  id: number;
  userId: number;
  name: string;
  picUrl: string;
  coverImgUrl: string;
  playCount: number;
  tags: string[];
  createTime: number;
  creator: { nickname: string; avatarUrl: string; };
  description: string;
  subscribedCount: number;
  shareCount: number;
  commentCount: number;
  subscribed: boolean;
  tracks: Song[];
}

export interface SheetParams {
  order: 'new' | 'hot';
  cat: string;
  limit: number;
  offset: number;
}

export interface SheetList {
  playlists: SongSheet[];
  total: number;
}

export interface Lyric {
  lyric: string;
  tlyric: string;
}

export type SingerDetail = {
  artist: Singer;
  hotSongs: Song[];
}

export interface SearchResult {
  albums?: SongSheet[];
  artists?: Singer[];
  songs?: Song[];
}