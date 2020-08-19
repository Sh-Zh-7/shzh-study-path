import { Injectable } from '@angular/core';
import { Resolve, ActivatedRouteSnapshot, RouterStateSnapshot } from '@angular/router';
import { Lyric, Song } from 'src/app/services/data-types/common.types';
import { forkJoin, Observable } from 'rxjs';
import { SongService } from 'src/app/services/song.service';
import { first } from 'rxjs/internal/operators';

type SongDataModel = [Song, Lyric];

@Injectable()
export class SongInfoService implements Resolve<SongDataModel> {
  constructor(private songService: SongService) {}

  resolve(route: ActivatedRouteSnapshot): Observable<SongDataModel> {
    const id = route.paramMap.get('id');
    return forkJoin([
      this.songService.getSongDetail(id),
      this.songService.getLyrics(Number(id))
    ]).pipe(first());
  }

}
