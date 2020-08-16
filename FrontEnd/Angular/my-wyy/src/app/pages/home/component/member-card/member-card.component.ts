import { Component, OnInit, Input } from '@angular/core';
import { MemberBatchActionService } from 'src/app/store/member-batch-actions.service';
import { User } from 'src/app/services/data-types/member.type';
import { MemberService } from 'src/app/services/member.service';

@Component({
  selector: 'app-member-card',
  templateUrl: './member-card.component.html',
  styleUrls: ['./member-card.component.less']
})
export class MemberCardComponent implements OnInit {

  @Input() user: User;
  constructor(
    private memberSerice: MemberService,
    private memberBatchActionService: MemberBatchActionService
  ) { }

  ngOnInit(): void {
  }

  onClick() {
    this.memberBatchActionService.controlModal();
  }

  onSignin() {
    this.memberSerice.signIn().subscribe(
      res => console.log(res),
      error => console.log(error)
    )
  }

}
