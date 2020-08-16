import { Component } from '@angular/core';
import { SearchService } from './services/search.service';
import { SearchResult } from './services/data-types/common.types';
import { MemberBatchActionService } from './store/member-batch-actions.service';
import { LoginParams } from './share/wy-ui/wy-layer/wy-layer-login/wy-layer-login.component';
import { MemberService } from './services/member.service';
import { NzMessageService } from 'ng-zorro-antd';
import { User } from './services/data-types/member.type';
import { StorageService } from './services/storage.service';
import { codeJson } from './utils/base64';
import { Store } from '@ngrx/store';
import { AppStoreModule } from './store';
import { SetUserId } from './store/actions/member.actions';

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
  }]

  searchResult: SearchResult;

  user: User;
  wyRememberLogin: LoginParams;

  constructor(
    private store$: Store<AppStoreModule>,
    private searchService: SearchService,
    private memberService: MemberService,
    private messageService: NzMessageService,
    private storageService: StorageService,
    private memberBatchServices: MemberBatchActionService
  ) {
    // 从localStorage中获取信息
    const userId = this.storageService.getStorage('wyUserId');
    if (userId) {
      this.store$.dispatch(SetUserId({userId: userId}));
      this.memberService.getUserDetail(userId).subscribe(user => this.user = user);
    }
    const wyRememberLogin = this.storageService.getStorage('wyRememberLogin')
    if (wyRememberLogin) {
      this.wyRememberLogin = JSON.parse(wyRememberLogin);
    }

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
          item.name = item.name.replace(reg, '<span class="highlight">$&</span>')
        })
      }
    })
    return result;
  }

  onChangeModalType(type) {
    this.memberBatchServices.controlModal(true, type);
  }

  onLogin(loginParam: LoginParams) {
    this.memberService.login(loginParam).subscribe(res => {
      this.user = res;
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
        })
      } else {
        this.storageService.removeStorage('wyRememberLogin')
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
      this.storageService.removeStorage('wyUserId')
    }, this.handleErrorMessage)
  }

  handleErrorMessage(err) {
    this.alertMessage('error', err.message);
  }
} 
