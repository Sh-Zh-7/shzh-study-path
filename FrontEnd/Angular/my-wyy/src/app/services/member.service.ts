import { Injectable, Inject } from '@angular/core';
import { HttpClient, HttpParams } from '@angular/common/http';
import { API_CONFIG, ServicesModule } from './services.module';
import { LoginParams } from '../share/wy-ui/wy-layer/wy-layer-login/wy-layer-login.component';
import queryString from 'query-string';
import { User, SignIn, recordVal, UserRecord, UserSheet } from './data-types/member.type';
import { map } from 'rxjs/internal/operators';
import { Observable } from 'rxjs';
import { SongSheet } from './data-types/common.types';
import { stringify } from 'querystring';

export enum RecordType {
  allData,
  weekData
}

const records = ['allData', 'weekData'];


@Injectable({
  providedIn: ServicesModule
})
export class MemberService {
  constructor(
    private http: HttpClient,
    @Inject(API_CONFIG) private urlPrefix
  ) {}

  login(loginParam: LoginParams): Observable<User> {
    const usernamePasswordPair = {phone: loginParam.phone, password: loginParam.password};
    const param = new HttpParams({fromString: queryString.stringify(usernamePasswordPair)});
    return this.http.get(this.urlPrefix + 'login/cellphone', {params: param}).pipe(
      map(user => user as User)
    );
  }

  getUserDetail(id: string): Observable<User> {
    const params = new HttpParams().set('uid', id);
    return this.http.get(this.urlPrefix + 'user/detail', {params}).pipe(map(user => user as User));
  }

  signIn(): Observable<SignIn> {
    const params = new HttpParams().set('type', (1).toString());
    return this.http.get(this.urlPrefix + 'daily_signin', {params}).pipe(map(res => res as SignIn));
  }

  logout() {
    return this.http.get(this.urlPrefix + 'logout');
  }

    // 听歌记录
    getUserRecord(uid: string, type = RecordType.weekData): Observable<recordVal[]> {
      const params = new HttpParams({ fromString: queryString.stringify({ uid, type }) });
      return this.http.get(this.urlPrefix + 'user/record', { params })
      .pipe(map((res: UserRecord) => res[records[type]]));
    }

    // 用户歌单
    getUserSheets(uid: string): Observable<UserSheet> {
      const params = new HttpParams({ fromString: queryString.stringify({ uid }) });
      return this.http.get(this.urlPrefix + 'user/playlist', { params })
      .pipe(map((res: { playlist: SongSheet[] }) => {
        const list = res.playlist;
        return {
          self: list.filter(item => !item.subscribed),
          subscribed: list.filter(item => item.subscribed)
        };
      }));
    }

    sendCaptcha(phone: string) {
      const params = new HttpParams().set('phone', phone);
      return this.http.get(this.urlPrefix + 'captcha/sent', { params })
        .pipe(map((res: {code: number}) => res.code));
    }

    verifyCaptcha({phone, captcha}) {
      const params = new HttpParams({ fromString: queryString.stringify({ phone, captcha})});
      return this.http.get(this.urlPrefix + 'captcha/verify', { params })
        .pipe(map((res: { code: number }) => res.code));
    }

    checkExistence(phone: string) {
      const params = new HttpParams().set('phone', phone);
      return this.http.get(this.urlPrefix + 'register/cellphone', { params })
        .pipe(map((res: {code: number}) => res.code));
    }
}
