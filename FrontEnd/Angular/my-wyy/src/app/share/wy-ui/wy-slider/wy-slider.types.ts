import { Observable } from 'rxjs';

export interface TrackStyle {
  height?: string | null;
  width?: string | null;
  left?: number | null;
  bottom?: number | null;
}

export interface SliderEventObserverConfig {
  // Event names
  start: string;
  move: string;
  end: string;
  // Operator parameters
  filterFunc: (e: Event) => boolean;
  pluckKey: string[];
  // Observabl, end with $
  startPlucked$?: Observable<number>;
  moveResolved$?: Observable<number>;
  end$?: Observable<Event>;
}

export type SliderValue = number | null;
