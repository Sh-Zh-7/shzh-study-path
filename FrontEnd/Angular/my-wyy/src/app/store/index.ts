import { NgModule } from '@angular/core';
import { playerReducer } from './reducers/player.reducers';
import { StoreModule } from '@ngrx/store';
import { StoreDevtoolsModule } from '@ngrx/store-devtools';
import { environment } from 'src/environments/environment';
import { MemberReducer } from './reducers/member.reducers';



@NgModule({
  declarations: [],
  imports: [
    StoreModule.forRoot({player: playerReducer, member: MemberReducer}, {
      // 主要是检查不规范的事情的
      runtimeChecks: {
        strictStateImmutability: true,
        strictActionImmutability: true,
        strictStateSerializability: true,
        strictActionSerializability: true,
        strictActionWithinNgZone: true,
        strictActionTypeUniqueness: true,
      }
    }),
    StoreDevtoolsModule.instrument({
      maxAge: 20,
      logOnly: environment.production
    })
  ]
})
export class AppStoreModule { }
