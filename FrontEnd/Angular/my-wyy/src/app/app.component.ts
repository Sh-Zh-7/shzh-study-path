import { Component } from '@angular/core';
import { SearchService } from './services/search.service';
import { SearchResult } from './services/data-types/common.types';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.less']
})
export class AppComponent {
  title = 'my-wyy';
  menu = [{
    label: '发现',
    path: '/home'
  }, {
    label: '菜单',
    path: '/sheet'
  }]

  searchResult: SearchResult;

  constructor(private searchService: SearchService) {}

  onSearch(value: string) {
    this.searchService.search(value).subscribe(result => {
      this.searchResult = this.highlightText(value, result);
    });
  }

  private highlightText(keyword: string, result: SearchResult) {
    const reg = new RegExp(keyword, 'ig');
    ['albums', 'artists', 'songs'].forEach(type => {
      if (result[type]) {
        result[type].forEach(item => {
          item.name = item.name.replace(reg, '<span class="highlight">$&</span>')
        })
      }
    })
    return result;
  }
}
