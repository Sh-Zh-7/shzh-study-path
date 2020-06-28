import { max } from 'rxjs/internal/operators';

export function limitNumberInRange(num: number, lower: number, upper: number) : number {
  return Math.min(Math.max(num, lower), upper);
}

export function getPercent(min: number, max: number, value: number): number {
  return (value - min) / (max - min) * 100;
}