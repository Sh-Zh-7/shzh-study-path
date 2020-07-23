export function sliderEvent(e: Event) {
  // 防止事件传递到其它节点
  e.stopPropagation();
  // 阻止一些默认的事件
  // 比如点击a标签就会跳转到href中的链接
  // preventDefault就可以阻止这种事情的发生
  e.preventDefault();
}

export function getElementOffset(el: HTMLElement): { top: number; left: number; } {
  if (!el.getClientRects().length) {
    return {
      top: 0,
      left: 0
    }
  }

  const rect = el.getBoundingClientRect();
  const win = el.ownerDocument.defaultView;

  return {
    // pageYOffset和pageXOffset是窗口的水平和垂直方向的滚动
    top: rect.top + win.pageYOffset,
    left: rect.left + win.pageXOffset
  }
}