#include<iostream>
#include<string>
using std::istream;
using std::ostream;
using std::string;

class Person {
  friend istream &operator<<(istream&, Person&);
  friend ostream &operator>>(ostream&, const Person&);
 public:
  Person() = default;
  Person(const string &name, const string &addr)
      : name_(name), addr_(addr) {}
  // 注意不能使用引用返回值
  // 不然我就可以只用别的变量来修改你的private成员了
  const string &GetName() const { return name_; }
  const string &GetAddress() const { return addr_; }
 private:
  string name_;
  string addr_;
};

istream &operator<<(istream &in, Person &p) {
  in >> p.name_ >> p.addr_;
  return in;
}

ostream & operator>>(ostream &out, const Person &p) {
  out << p.name_ << " " 
      << p.addr_;
  return out;
}

int main() {
  using namespace std;
  return 0;
}