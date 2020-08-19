import { Injectable, Inject } from '@angular/core';
import { ServicesModule, API_CONFIG } from './services.module';
import { Observable } from 'rxjs';
import { Banner, HotTag, SongSheet } from './data-types/common.types';
import { HttpClient } from '@angular/common/http';
import { map } from 'rxjs/internal/operators';

@Injectable({
  // 把服务提供给当前模块
  providedIn:  ServicesModule
})
export class HomeService {
  constructor(
    private http: HttpClient,
    @Inject(API_CONFIG) private prefix: string
  ) { }

  // 在服务里写明你需要那些服务
  // 在其它模块中需要用到服务的使用，就调用这个接口
  getBanner(): Observable<Banner[]> {
    return this.http.get(this.prefix + 'banner')
    .pipe(map((res: {banners: Banner[]}) => res.banners));
  }

  getHotTags(): Observable<HotTag[]> {
    // 注意map的语法map(xx => xx)
    return this.http.get(this.prefix + 'playlist/hot')
    .pipe(map((res: {tags: HotTag[]}) => res.tags.sort(
      (a: HotTag, b: HotTag) => a.position - b.position
    ).slice(0, 5)));
    // 这里不能用take, 因为数据源是一次性发送一个数组，而不是一个一个数据地发
  }

  getPersonalSheetList(): Observable<SongSheet[]> {
    return this.http.get(this.prefix + 'personalized')
    .pipe(map((res: {result: SongSheet[]}) => res.result.slice(0, 16)));
  }
}
