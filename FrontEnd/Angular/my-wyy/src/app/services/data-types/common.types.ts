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

export interface SongSheet {
  id: number;
  name: string;
  playCount: number;
  picUrl: string;
}

export interface Singer {
  name: string;
  picUrl: string;
  albumSize: number;
}