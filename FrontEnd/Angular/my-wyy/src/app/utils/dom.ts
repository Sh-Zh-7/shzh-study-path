export function getHideDomSize(dom: HTMLElement) {
  return {
    w: dom.offsetWidth,
    h: dom.offsetHeight
  }
}

export function getWindowSize() {
  return {
    w: window.innerWidth || document.documentElement.clientWidth || document.body.offsetWidth,
    h: window.innerHeight || document.documentElement.clientHeight || document.body.offsetHeight
  }
}