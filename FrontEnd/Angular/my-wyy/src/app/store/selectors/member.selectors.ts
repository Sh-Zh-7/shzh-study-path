import { createSelector, createFeatureSelector } from '@ngrx/store';
import { ModalState } from '../reducers/member.reducers';

const selectModalStates = (state: ModalState) => state;

export const getModal = createFeatureSelector<ModalState>('member');

export const getModalVisiable = createSelector(selectModalStates, (state: ModalState) => state.modalVisiable);
export const getModalType = createSelector(selectModalStates, (state: ModalState) => state.modalType);
export const getUserId = createSelector(selectModalStates, (state: ModalState) => state.userId);
export const getLikeId = createSelector(selectModalStates, (state: ModalState) => state.likeId);
