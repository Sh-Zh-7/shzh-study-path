import { createReducer, on, Action } from '@ngrx/store';
import { SetPlaying, SetPlayList, SetSongList, SetPlayMode, SetCurrentIndex } from '../actions/player.actions';
import { SetModalVisiable, SetModalType, SetUserId } from '../actions/member.actions';

// 这还能用字符串定义枚举类型吗
export enum ModalType {
  Register = 'Register',
  LoginByPhone = 'LoginByPhone',
  Default = 'Default'
}

export interface ModalState {
  modalVisiable: boolean;
  modalType: ModalType;
  userId: string;
}

export const initialState: ModalState = {
  modalVisiable : false,
  modalType : ModalType.Default,
  userId: ''
}

// 返回一个类啊
// 使用的时候不用传递state参数，他会自动调用当前的state
const reducer = createReducer(
  initialState,
  // 这里的必须得和PlayState中的属性一致
  on(SetModalVisiable, (state, { modalVisiable }) => ({...state, modalVisiable})),
  on(SetModalType, (state, { modalType }) => ({...state, modalType})),
  on(SetUserId, (state, {userId}) => ({...state, userId}))
)

export function MemberReducer(state: ModalState, action: Action) {
  return reducer(state, action);
}

