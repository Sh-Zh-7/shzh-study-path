import { Injectable, Inject } from "@angular/core";
import { HttpClient, HttpParams } from '@angular/common/http';
import { API_CONFIG, ServicesModule } from './services.module';
import { LoginParams } from '../share/wy-ui/wy-layer/wy-layer-login/wy-layer-login.component';
import queryString from 'query-string';
import { User, SignIn } from './data-types/member.type';
import { map } from 'rxjs/internal/operators';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: ServicesModule
})
export class MemberService {
  constructor(
    private http: HttpClient,
    @Inject(API_CONFIG) private urlPrefix
  ) {}

  login(loginParam: LoginParams): Observable<User> {
    const usernamePasswordPair = {phone: loginParam.phone, password: loginParam.password}
    const param = new HttpParams({fromString: queryString.stringify(usernamePasswordPair)});
    return this.http.get(this.urlPrefix + "login/cellphone", {params: param}).pipe(
      map(user => user as User)
    )
  }

  getUserDetail(id: string): Observable<User> {
    const params = new HttpParams().set("uid", id);
    return this.http.get(this.urlPrefix + "user/detail", {params: params}).pipe(map(user => user as User));
  }

  signIn(): Observable<SignIn> {
    const params = new HttpParams().set("type", (1).toString());
    return this.http.get(this.urlPrefix + "daily_signin", {params: params}).pipe(map(res => res as SignIn));
  }

  logout() {
    return this.http.get(this.urlPrefix + "logout");
  }
}