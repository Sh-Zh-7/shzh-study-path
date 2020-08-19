export function IsEmptyObj(obj: Object): boolean {
  return JSON.stringify(obj) === '{}';
}
