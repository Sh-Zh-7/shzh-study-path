#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 使用委托构造函数
class SalesItem {
 public:
  SalesItem(const string &book_no, unsigned units_sold,
            double selling_price, double sale_price) 
      : book_no_(book_no), units_sold_(units_sold),
        selling_price_(selling_price), sale_price_(sale_price) {
          cout << "calling the big function\n";
          if (selling_price) {
            discount_ = sale_price_ / selling_price;
          } else {
            discount_ = 0.;
          }
        }
  SalesItem() : SalesItem("", 0, 0.0, 0.0) { cout << "calling the default function.\n"; }
  SalesItem(const string &book_no) : SalesItem(book_no, 0, 0.0, 0.0) {
    cout << "calling the string function.\n";
  }
 
 private:
  string book_no_;
  // 迷惑——我的默认构造函数给委托构造函数传递了初始值
  // 那我岂不是这里的类内初始值都不需要了吗？无语了
  unsigned units_sold_ = 0;
  double selling_price_ = 0.;
  double sale_price_ = 0.;
  double discount_ = 0.0;
};

int main() {
  SalesItem item1;
  SalesItem item2("666");
  system("pause>nul");
  return 0;
}
