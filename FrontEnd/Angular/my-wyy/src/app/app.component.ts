import { Component } from '@angular/core';
import { SearchService } from './services/search.service';
import { SearchResult } from './services/data-types/common.types';
import { MemberBatchActionService } from './store/member-batch-actions.service';
import { LoginParams } from './share/wy-ui/wy-layer/wy-layer-login/wy-layer-login.component';
import { MemberService } from './services/member.service';
import { NzMessageService } from 'ng-zorro-antd';
import { User, UserSheet } from './services/data-types/member.type';
import { StorageService } from './services/storage.service';
import { codeJson } from './utils/base64';
import { Store } from '@ngrx/store';
import { AppStoreModule } from './store';
import { SetUserId, SetModalVisiable } from './store/actions/member.actions';
import { ModalType } from './store/reducers/member.reducers';
import { Router, ActivatedRoute, NavigationEnd, NavigationStart } from '@angular/router';
import { Title } from '@angular/platform-browser';
import { Observable, interval } from 'rxjs';
import { filter, map, mergeMap, takeUntil } from 'rxjs/internal/operators';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.less']
})
export class AppComponent {
  title = 'my-wyy';
  menu = [{
    label: '发现',
    path: '/home'
  }, {
    label: '菜单',
    path: '/sheet'
  }];

  searchResult: SearchResult;

  user: User;
  mySongSheet: UserSheet;
  wyRememberLogin: LoginParams;

  navStart: Observable<NavigationStart>;
  navEnd: Observable<NavigationEnd>;

  routeTitle: string;

  loadPercent = 0;

  constructor(
    private store$: Store<AppStoreModule>,
    private searchService: SearchService,
    private memberService: MemberService,
    private messageService: NzMessageService,
    private storageService: StorageService,
    private memberBatchServices: MemberBatchActionService,
    private router: Router,
    private activatedRoute: ActivatedRoute,
    private titleService: Title
  ) {
    // 从localStorage中获取信息
    const userId = this.storageService.getStorage('wyUserId');
    if (userId) {
      this.store$.dispatch(SetUserId({userId}));
      this.memberService.getUserDetail(userId).subscribe(user => this.user = user);
    }
    const wyRememberLogin = this.storageService.getStorage('wyRememberLogin');
    if (wyRememberLogin) {
      this.wyRememberLogin = JSON.parse(wyRememberLogin);
    }
    // 设置各个页面标题
    this.navStart = (this.router.events.pipe(filter(evt => evt instanceof NavigationStart)) as Observable<NavigationStart>);
    this.navEnd = (this.router.events.pipe(filter(evt => evt instanceof NavigationEnd)) as Observable<NavigationEnd>);

    this.navStart.subscribe(() => {
      this.setTitle();
      this.setLoadingBar();
    });
  }

  setLoadingBar() {
    interval(100).pipe(takeUntil(this.navEnd)).subscribe(() => {
      this.loadPercent = Math.max(95, ++this.loadPercent);
    });
    this.navEnd.subscribe(() => {
      this.loadPercent = 100;
    });
  }

  setTitle() {
    this.navEnd.pipe(
      map(() => this.activatedRoute),
      map((route: ActivatedRoute) => {
        while (route.firstChild) {
          route = route.firstChild;
        }
        return route;
      }),
      mergeMap(route => route.data)
    ).subscribe(data => {
      this.routeTitle = data.title;
      this.titleService.setTitle(this.routeTitle);
    });
  }

  onSearch(value: string) {
    this.searchService.search(value).subscribe(result => {
      this.searchResult = this.highlightText(value, result);
    });
  }

  private highlightText(keyword: string, result: SearchResult) {
    const reg = new RegExp(keyword, 'ig');
    ['albums', 'artists', 'songs'].forEach(type => {
      if (result[type]) {
        result[type].forEach(item => {
          item.name = item.name.replace(reg, '<span class="highlight">$&</span>');
        });
      }
    });
    return result;
  }

  onChangeModalType(type) {
    this.memberBatchServices.controlModal(true, type);
  }

  onLogin(loginParam: LoginParams) {
    this.memberService.login(loginParam).subscribe(res => {
      this.user = res;
      console.log(this.user);
      this.memberBatchServices.controlModal(false);
      this.alertMessage('success', '登陆成功!');
      this.storageService.setStorage({
        key: 'wyUserId',
        value: this.user.profile.userId.toString()
      });
      this.store$.dispatch(SetUserId({userId: this.user.profile.userId.toString()}));

      if (loginParam.remember) {
        this.storageService.setStorage({
          key: 'wyRememberLogin',
          value: JSON.stringify(codeJson(loginParam))
        });
      } else {
        this.storageService.removeStorage('wyRememberLogin');
      }

    }, this.handleErrorMessage);
  }

  private alertMessage(type: string, msg: string) {
    this.messageService.create(type, msg);
  }

  onLogout() {
    this.memberService.logout().subscribe(() => {
      this.alertMessage('success', '退出成功!');
      this.user = null;
      this.store$.dispatch(SetUserId({userId: null}));
      this.storageService.removeStorage('wyUserId');
    }, this.handleErrorMessage);
  }

  handleErrorMessage(err) {
    this.alertMessage('error', err.message);
  }

  onLoadSongSheet() {
    if (this.user) {
      this.memberService.getUserSheets(this.user.profile.userId.toString()).subscribe(songsheet => {
        this.mySongSheet = songsheet;
        this.store$.dispatch(SetModalVisiable({ modalVisiable: true }));
      });
    } else {
      this.memberBatchServices.controlModal(true, ModalType.Default);
    }
  }

  onRegister() {
    this.messageService.info('注册成功');
  }
}
