#include<iostream>
#include<string>
// 尽早的using指令可以让我们的函数声明更加方便
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;

class SalesItem {
  // Friend functions
  friend istream &operator>>(istream&, SalesItem&);
  friend ostream &operator<<(ostream&, const SalesItem&);
 public:
  // Rule of Three 
  SalesItem() = default;    // Default cntr（使用keyword default + 默认初始化值来进行初始化？）
  SalesItem(const SalesItem&) = default;    // Copy cntr（这里使用const引用是可以接受任意非const或const对象）
  SalesItem& operator=(SalesItem);   // Assignment
  ~SalesItem() = default;     // dntr

  // Operator overload
  SalesItem& operator+=(const SalesItem&);
  bool operator==(const SalesItem&) const;
  bool operator!=(const SalesItem& item) const {
    return !operator==(item);
  }

  // Others
  string Isbn() const { return isbn_; }
 private:
  string isbn_;
  double num_ = 0.;
  double price_ = 0.;
};

// class后面必须要有分号，不然会报各种未知错误
istream &operator>>(istream &in, SalesItem& item) {
  in >> item.isbn_ >> item.num_ >> item.price_;
  return in;
}

ostream &operator<<(ostream &out, const SalesItem& item) {
  out << item.isbn_ << " "
      << item.num_ << " "
      << item.num_ * item.price_ << " "
      << item.price_;
  return out;
}

// 在选择是否添加const的过程中
// 我们应当时刻注意非常量引用这一类型
// 对于普通的const，一般都是顶层const，传const或非const对象都无所谓
// 对于const引用，虽然他很特殊，但他依然可以接受const或非const对象
// 只有非const引用，它不能接受const对象——只有它会产生参数不能正确转换的错误
SalesItem& SalesItem::operator+=(const SalesItem &item) {
  int sum = num_ * price_ + item.num_ * item.price_;
  this->num_ += item.num_;
  this->price_ = sum / num_;
  return *this;
}

// 突然发现一个很矛盾的现象
// 因为类的设计可能会很大， 所以一般我们传参和返回值都是利用引用
// 但是如果我们不想他成为左值，只能返回常引用，使之成为不可修改的左值
// （运算符的嵌套这里倒没怎么体现，实际上你返回常引用仍然可以被正确嵌套）

// 如果返回（常量非常量都是）引用的话，那返回值必然是你传入的引用参数（可能修改，也可能不被修改）
// 显然未经修改的引用作为返回值没啥意义，所以返回引用基本上就是返回修改了的参数本身！
template<typename T>
T operator+(const T& a, const T& b) {    // 所以这个东西该怎么写呢？
// 这里使用了一种非常tricky的方法
  // T temp(a);    // copy cntr的作用体现出来了
  // temp += b;
  // return temp; 
  // 注释掉的这段代码要执行两次copy和一次+=
  // 而我下面这段只要执行一次copy和一次=
  // return a += b;
  T temp(a);    // copy cntr可以将const引用转化为普通的对象！！
  temp += b;
  return temp;
}

bool SalesItem::operator==(const SalesItem& item) const {
  return (isbn_ == item.isbn_)
      && (num_ == item.num_)
      && (price_ == item.price_);
}

// 这里又有矛盾了，对于赋值运算符，我理应传入const引用
// 但是如果我是使用swap的话，那必然要修改我传入的引用
// 不知道到底是怎么实现的
SalesItem& SalesItem::operator=(SalesItem item) {
// 很奇怪，这里使用了pass by value
// 去StackOverflow看看https://stackoverflow.com/questions/3279543/what-is-the-copy-and-swap-idiom
  std::swap(isbn_, item.isbn_);
  std::swap(num_, item.num_);
  std::swap(price_, item.price_);
  return *this;
}

int main() {
  SalesItem total;
  if (cin >> total) {
    SalesItem temp;
    while (cin >> temp) {
    // 从输入流中不断读取值放入temp中
      if (temp.Isbn() == total.Isbn()) {
      // 处理isbn相同的情况
        total += temp;
      } else {
      // 处理isbn不同的情况
        cout << total << endl;
        total = temp;
      }
    }
  } else {
  // 处理无输入的情况
    cout << "No Data!\n";
    system("pause>nul");
    return -1;
  }
  cout << total << endl;
  system("pause>nul");
  return 0;
}




