import { Injectable, Inject } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { ServicesModule, API_CONFIG } from './services.module';
import { Singer } from './data-types/common.types';
import { Observable } from 'rxjs';
import { map } from 'rxjs/internal/operators';
import queryString from 'query-string';

interface QueryParam {
  cat: number;
  limit: number;
  offset: number;
}

const defaultParam: QueryParam = {
  cat: 1001,
  limit: 9,
  offset: 0
}

@Injectable({
  providedIn: ServicesModule
})
export class SingerService {
  constructor(
    private http: HttpClient,
    @Inject(API_CONFIG) private prefix: string,  
  ) {}

  getSingerList(queryParam: QueryParam = defaultParam) :Observable<Singer[]> {
    let param = new HttpParams({fromString: queryString.stringify(queryParam)})
    return this.http.get(this.prefix + "artist/list", {params: param})
    .pipe(map((res: { artists: Singer[] }) => res.artists));
  }
}
