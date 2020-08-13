import { Injectable } from "@angular/core";
import { SingerDetail } from 'src/app/services/data-types/common.types';
import { Resolve, ActivatedRouteSnapshot } from '@angular/router';
import { Observable } from 'rxjs';
import { SingerService } from 'src/app/services/singer.service';

@Injectable()
export class SingerDetailResolverService implements Resolve<SingerDetail> {
  constructor(private singerService: SingerService) {}

  resolve(route: ActivatedRouteSnapshot): Observable<SingerDetail> {
    const id = route.paramMap.get('id');
    return this.singerService.getSingerDetail(Number(id));
  }
}