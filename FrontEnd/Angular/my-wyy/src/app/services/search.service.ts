import { Injectable, Inject } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { API_CONFIG } from './services.module';
import { Observable } from 'rxjs';
import { SearchResult } from './data-types/common.types';
import { map } from 'rxjs/internal/operators';

@Injectable({
  providedIn: 'root'
})
export class SearchService {

  constructor(private http: HttpClient, @Inject(API_CONFIG) private prefix) { }

  search(keywords: string): Observable<SearchResult> {
    const params = new HttpParams().set('keywords', keywords);
    return this.http.get(this.prefix + 'search/suggest', {params})
      .pipe(map((res: {result: SearchResult}) => res.result));
  }
}
