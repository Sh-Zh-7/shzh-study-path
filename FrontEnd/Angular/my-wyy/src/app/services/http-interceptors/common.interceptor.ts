import { Injectable } from '@angular/core';
import { HttpInterceptor, HttpRequest, HttpHandler, HttpEvent } from '@angular/common/http';
import { Observable } from 'rxjs';
import { catchError } from 'rxjs/internal/operators';

@Injectable()
export class CommonInterceptor implements HttpInterceptor {
  intercept(req: HttpRequest<any>, next: HttpHandler): Observable<HttpEvent<any>> {
    // 允许跨域的cookie
    return next.handle(req.clone({
      withCredentials: true
    })).pipe(catchError(this.handleError));
  }

  handleError(error: any): never {
    // 处理错误信息
    throw error.error;
  }


}
