import { Pipe, PipeTransform } from '@angular/core';

@Pipe({
  name: 'formatTimePipeTs'
})
export class FormatTime implements PipeTransform {
  // Transform的参数是接受的参数，返回的就是处理后的字符串
  transform(time: number): string {
    if (time) {
      const temp = time | 0;
      const minute = temp / 60 | 0;
      const second = (temp % 60).toString().padStart(2, '0');
      return `${minute}:${second}`;
    } else {
      return '00:00';
    }
  }

}
