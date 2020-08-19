import { Injectable, Inject } from '@angular/core';
import { ServicesModule, API_CONFIG } from './services.module';
import { HttpClient, HttpParams } from '@angular/common/http';
import { SongSheet, Song, SheetParams, SheetList } from './data-types/common.types';
import { Observable } from 'rxjs';
import { map, pluck, switchMap } from 'rxjs/internal/operators';
import { SongService } from './song.service';
import queryString from 'query-string';

@Injectable({
  providedIn: ServicesModule
})
export class SongSheetService {
  constructor(
    private http: HttpClient,
    private songService: SongService,
    @Inject(API_CONFIG) private prefix: string
  ) {}

  getSongSheet(id: number): Observable<SongSheet> {
    const arg = new HttpParams().set('id', id.toString());
    // 注意给http传递参数
    return this.http.get(this.prefix + 'playlist/detail', {params: arg})
    .pipe(map((res: { playlist: SongSheet }) => res.playlist));
  }

  getPlayList(args: SheetParams): Observable<SheetList> {
    const targetArgs = new HttpParams({fromString: queryString.stringify(args)});
    return this.http.get(this.prefix + 'top/playlist', {params: targetArgs})
    .pipe(map(res => res as SheetList));
  }


  playSheet(id: number): Observable<Song[]> {
    return this.getSongSheet(id)
    .pipe(pluck('tracks'), switchMap(res => this.songService.getSongList(res)));
  }
}
