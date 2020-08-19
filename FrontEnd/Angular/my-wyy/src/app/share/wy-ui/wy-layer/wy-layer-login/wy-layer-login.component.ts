import { Component, OnInit, Output, EventEmitter, OnChanges, SimpleChanges, Input } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';
import { codeJson } from 'src/app/utils/base64';

export type LoginParams = {
  phone: string;
  password: string;
  remember: boolean;
};

@Component({
  selector: 'app-wy-layer-login',
  templateUrl: './wy-layer-login.component.html',
  styleUrls: ['./wy-layer-login.component.less']
})
export class WyLayerLoginComponent implements OnInit, OnChanges {

  @Input() wyRememberLogin: LoginParams;
  @Output() onChangeModalType = new EventEmitter<string | void>();
  @Output() onLogin = new EventEmitter<LoginParams>();
  formModal: FormGroup;

  constructor(private fb: FormBuilder) {
    this.setFormModal({phone: '', password: '', remember: false});
  }
  ngOnChanges(changes: SimpleChanges): void {
    if (this.wyRememberLogin && changes.wyRememberLogin) {
      const value = codeJson(this.wyRememberLogin, 'decode');
      const phone = value.phone;
      const password = value.phone;
      const remember = value.remember;
      this.setFormModal({phone, password, remember});
    }
  }

  setFormModal({phone, password, remember}) {
    this.formModal = this.fb.group({
      phone: [phone, [Validators.required, Validators.pattern(/^1\d{10}$/)]],
      password: [password, [Validators.required, Validators.minLength(6)]],
      remember: [remember]
    });
  }

  ngOnInit(): void { }

  onSubmit(): void {
    if (this.formModal.valid) {
      this.onLogin.emit(this.formModal.value);
    }
  }
}
