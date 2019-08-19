#include<iostream>

int main() {
  int lv, rv;
  std::cin >> lv >> rv;
  for (int i = lv; i <= rv; ++i) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  system("pause>nul");
  return 0;
}