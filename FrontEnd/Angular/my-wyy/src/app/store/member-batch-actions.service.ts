import { Injectable } from "@angular/core";
import { AppStoreModule } from '.';
import { Store, select } from '@ngrx/store';
import { ModalState, ModalType } from './reducers/member.reducers';
import { SetModalVisiable, SetModalType } from './actions/member.actions';
import { getModal } from './selectors/member.selectors';

@Injectable(
  {providedIn: AppStoreModule}
)
export class MemberBatchActionService {
  private modalState: ModalState;

  constructor(private store$: Store<AppStoreModule>) {
    this.store$.pipe(select(getModal)).subscribe(modalState => this.modalState = modalState);
  }

  // Batch action services里面就是各种dispatch，这样就不用向外部暴露dispatch了
  controlModal(visiable = true, modalType?: ModalType) {
    this.store$.dispatch(SetModalVisiable({ modalVisiable: visiable }));
    this.store$.dispatch(SetModalType({ modalType: modalType }));
  }
}