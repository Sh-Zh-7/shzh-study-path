import { Component, OnInit, EventEmitter, Output } from '@angular/core';
import { FormGroup, FormBuilder, Validators } from '@angular/forms';
import { NzMessageService } from 'ng-zorro-antd';
import { MemberService } from 'src/app/services/member.service';
import { interval } from 'rxjs';
import { take } from 'rxjs/internal/operators';
import { ModalType } from 'src/app/store/reducers/member.reducers';

enum Exist {
  '存在' = 1,
  '不存在' = -1
}

@Component({
  selector: 'app-wy-layer-register',
  templateUrl: './wy-layer-register.component.html',
  styleUrls: ['./wy-layer-register.component.less'],
})
export class WyLayerRegisterComponent implements OnInit {
  @Output() onChangeModalType = new EventEmitter<string>();
  @Output() onRegister = new EventEmitter<void>();

  formModal: FormGroup;
  timing: number;
  showCode = false;

  codePass = true;

  constructor(
    private fb: FormBuilder,
    private messageService: NzMessageService,
    private memberService: MemberService
  ) {
    this.formModal = this.fb.group({
      phone: ['', [Validators.required, Validators.pattern(/^1\d{10}$/)]],
      password: ['', [Validators.required, Validators.minLength(6)]]
    });
  }

  ngOnInit(): void {
  }

  onSubmit() {
    if (this.formModal.valid) {
      this.sendCode();
    }
  }

  sendCode() {
    this.memberService.sendCaptcha(this.formModal.get('phone').value).subscribe(() => {
      this.timing = 60;
      if (!this.showCode) {
        this.showCode = true;
      }
      interval(1000).pipe(take(60)).subscribe(() => {
        this.timing--;
        console.log(this.timing);
      }), error => this.messageService.error(error.message);
    });
  }

  changeType(type = ModalType.Default) {
    this.onChangeModalType.emit(type);
    this.showCode = true;
    this.formModal.reset();
  }

  onCheckCode(code: string) {
    this.memberService.verifyCaptcha({phone: this.formModal.get('phone').value, captcha: Number(code)}).subscribe(
      () => this.codePass = true,
      () => this.codePass = false
    );
  }

  onCheckExist() {
    this.memberService.checkExistence(this.formModal.get('phone').value).subscribe(res => {
      if (Exist[res] === '存在') {
        this.messageService.error('帐号已存在，可直接登录');
        this.changeType(ModalType.LoginByPhone);
      } else {
        this.onRegister.emit();
      }
    });
  }

}
