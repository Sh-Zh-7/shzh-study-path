import { Component, OnInit, ChangeDetectionStrategy, Input, EventEmitter, Output, OnChanges, SimpleChanges } from '@angular/core';
import { FormBuilder, FormGroup, Validators } from '@angular/forms';

@Component({
  selector: 'app-wy-check-code',
  templateUrl: './wy-check-code.component.html',
  styleUrls: ['./wy-check-code.component.less'],
  changeDetection: ChangeDetectionStrategy.OnPush
})
export class WyCheckCodeComponent implements OnInit, OnChanges {
  @Input() timing = -1;
  @Input() codePass: boolean;
  @Output() onCheckCode = new EventEmitter<string>();
  @Output() onRegister = new EventEmitter<void>();
  @Output() onRepeatSendCode = new EventEmitter<void>();

  private phoneHideStr = '';
  formModel: FormGroup;
  showRepeatBtn = false;

  constructor(private fb: FormBuilder) {
    this.formModel = this.fb.group({
      code: ['', [Validators.required, Validators.pattern(/\d{4}/)]]
    });

    const codeControl = this.formModel.get('code');
    codeControl.statusChanges.subscribe(status => {
      console.log(status);
      console.log(codeControl.value);
      if (status === 'VALID') {
        this.onCheckCode.emit(codeControl.value);
      }
    });
  }

  ngOnChanges(changes: SimpleChanges): void {
    if (changes.timing) {
      this.showRepeatBtn = this.timing <= 0;
    }
  }

  ngOnInit(): void {
  }

  // Input和Set的组合
  @Input()
  set phone(phone: string) {
    const arr = phone.split('');
    arr.splice(3, 4, '****');
    this.phoneHideStr = arr.join('');
  }

  get phone() {
    return this.phoneHideStr;
  }

  onSubmit() {
    this.onRegister.emit();
  }

}
