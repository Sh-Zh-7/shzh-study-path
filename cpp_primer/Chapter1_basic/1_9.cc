#include<iostream>

int main() {
  int i = 50;
  int sum = 0;
  while (i <= 100) {
    sum += i;
    ++i;
  }
  std::cout << sum << std::endl;
  // 像这里就只需要使用一个std::cin.get()
  std::cin.get();
  return 0;
}