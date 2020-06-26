import { Injectable, Inject } from '@angular/core';
import { ServicesModule, API_CONFIG } from './services.module';
import { HttpClient, HttpParams } from '@angular/common/http';
import { Observable } from 'rxjs';
import { map } from 'rxjs/internal/operators';
import { SongUrl, Song } from './data-types/common.types';

@Injectable({
  providedIn: ServicesModule
})
export class SongService {
  constructor(
    private http: HttpClient,
    @Inject(API_CONFIG) private prefix: string
  ) { }

  // 这里之所以能这么传，是因为后端已经为我们准备好了接口
  getSongUrl(ids: string): Observable<SongUrl[]> {
    const params = new HttpParams().set("id", ids);
    return this.http.get(this.prefix + "song/url", {params})
    .pipe(map((res: {data: SongUrl[]}) => res.data));
  }

  getSongList(songs: Song | Song[]): Observable<Song[]> {
    // isArray和slice方法（防止引用）
    const songArr = Array.isArray(songs)? songs.slice() : [songs];
    const ids = songArr.map(item => item.id).join(",");

    return Observable.create(observer => {
      this.getSongUrl(ids).subscribe(urls => {
        observer.next(this.generateSongList(songArr, urls))
      })
    })
  }

  generateSongList(songs: Song[], urls: SongUrl[]) {
    const result = [];
    songs.forEach(song => {
      const url = urls.find(url => url.id === song.id).url;
      if (url) {
        result.push({...song, url});
      }
    })
    return result;
  }
}
