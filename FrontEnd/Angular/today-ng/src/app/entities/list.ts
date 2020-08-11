import { generateUUID } from '../utils/uuid';

export class List {
  _id: string;
  title: string;
  createdAt: number;

  constructor(title: string) {
    this._id = generateUUID();
    this.title = title;
  }
}