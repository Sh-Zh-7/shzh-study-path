#include<iostream>

int main() {
  constexpr int kSize = 10;
  int a[kSize];
  int *p = a;
  while (p != &a[kSize]) {
    *p++ = 0;
  }
  // 使用range-for和const auto ref输出
  for (const auto &i : a) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  system("pause>nul");
  return 0;
}