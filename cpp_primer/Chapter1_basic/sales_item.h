#ifndef SALES_ITEM_H__
#define SALES_ITEM_H__

#include<iostream>
#include<string>

class SalesItem {
 public:
  std::string ISBN() const { return isbn_; }
  
  // Bit manipulation overload
  // 不知为何这里得用引用，不然会报错isn't accessiable
  friend std::ostream& operator<<(std::ostream&, const SalesItem&);
  friend std::istream& operator>>(std::istream&, SalesItem&);

  // Arithmetic operator overload
  bool operator==(SalesItem&);
  bool operator!=(SalesItem&);
  const SalesItem& operator+=(SalesItem&);
  SalesItem operator+(SalesItem&);
 private:
  std::string isbn_;
  int number_;    // 销售册数
  double per_;    // 销售价格
  double total_;    // 销售总额
  double average_;   // 平均价格
};

#endif    // SALES_ITEM_H__ ends