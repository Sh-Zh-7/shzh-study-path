import { Component, OnInit, TemplateRef, ViewChild, Input, Output, EventEmitter } from '@angular/core';

@Component({
  selector: 'app-wy-carousel',
  templateUrl: './wy-carousel.component.html',
  styleUrls: ['./wy-carousel.component.less']
})
export class WyCarouselComponent implements OnInit {
  @Input() activeIndex = 0;
  @Output() slideChange = new EventEmitter<'pre' | 'next'>();
  // 注意声明为TemplateRef类型的对象必须是DOM中的ng-template元素
  @ViewChild('dot', {static: true}) dotRender: TemplateRef<any>;

  constructor() { }

  ngOnInit(): void {
  }

  onSlideChange(changeType: 'pre' | 'next') {
    this.slideChange.emit(changeType);
  }

}
