import { Injectable } from '@angular/core';
import { Resolve, ActivatedRouteSnapshot } from '@angular/router';
import { SongSheet } from 'src/app/services/data-types/common.types';
import { SongSheetService } from 'src/app/services/song-sheet.service';
import { Observable } from 'rxjs';

@Injectable()
export class SheetInfoResolveService implements Resolve<SongSheet> {
  constructor(private sheetService: SongSheetService) {}

  resolve(route: ActivatedRouteSnapshot): Observable<SongSheet> {
    return this.sheetService.getSongSheet(Number(route.paramMap.get('id')));
  }


}
