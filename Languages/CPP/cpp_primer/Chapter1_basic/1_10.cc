#include<iostream>

int main() {
  for (int i = 10; i >= 0; --i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  // 也可以直接放弃缓冲区的字符
  // 这样只要一个system("pause")就行
  system("pause");
  return 0;
}