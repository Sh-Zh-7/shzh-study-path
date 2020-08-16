import { createAction, props } from '@ngrx/store';
import { ModalType } from '../reducers/member.reducers';

export const SetModalVisiable = createAction('[member] Set modal visiablilty', props<{ modalVisiable: boolean}>());
export const SetModalType = createAction('[member] Set modal type', props<{ modalType: ModalType}>());
export const SetUserId = createAction('[member] Set user id', props<{userId: string}>());
