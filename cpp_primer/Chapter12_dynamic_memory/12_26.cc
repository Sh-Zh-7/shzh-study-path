#include<memory>
#include<iostream>

int main() {
  using namespace std;
  constexpr size_t n = 5;
  allocator<string> alloc;
  // allocate返回一个对应的指针类型
  const auto p = alloc.allocate(n);
  auto q = p;
  // p是初始地址的指针，q是一个可以移动的指针
  // q专门用来在分配的动态内存上构造对象

  string temp;  
  while (cin >> temp) {
    alloc.construct(q++, temp);
  }
  size_t size = q - p;

  // 当作普通的数组使用
  for (size_t i = 0; i < size; ++i) {
    cout << p[i] << " ";
  }
  cout << endl;

  while (q != p) {
    alloc.destroy(--q);
  }
  alloc.deallocate(p, n);

  system("pause>nul");
  return 0;
}