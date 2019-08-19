#include"sales_item.h"

bool SalesItem::operator==(SalesItem& item) {
  if ((isbn_ == item.isbn_) && (number_ == item.number_) && (average_ == item.average_)) {
    return true;
  } else {
    return false;
  }
}

bool SalesItem::operator!=(SalesItem& item) {
  return !operator==(item);
}

const SalesItem& SalesItem::operator+=(SalesItem& item) {
  total_ = number_ * per_ + item.number_ * item.per_;
  average_ = total_ / (number_ + item.number_);
  per_ = average_;
  number_ += item.number_;
  return *this;
}

SalesItem SalesItem::operator+(SalesItem& item) {
  // 虽然operator+=返回值是const reference类的
  // 但是我们依然可以通过这个植草出原来类的副本
  return operator+=(item);
}

std::ostream& operator<<(std::ostream& os, const SalesItem& item) {
  // 注意不能要有正确的函数特征标，不然IDE不会给你自动补全成员变量
  // （就是不认为它是成员函数）
  os << item.isbn_ << " " << item.number_ <<" " <<  item.total_
     << " " << item.average_;
  return os; 
}

std::istream& operator>>(std::istream& is, SalesItem& item) {
  is >> item.isbn_ >> item.number_ >> item.per_;
  item.total_ = item.per_ * item.number_;
  item.average_ = item.total_ / item.number_;
  return is;
}