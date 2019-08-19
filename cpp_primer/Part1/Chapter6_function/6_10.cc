#include<iostream>

void Swap(int &a, int &b) {
  std::swap(a, b);
}

int main() {
  int a = 1, b = 2;
  Swap(a, b);
  std::cout << "a = " << a << std::endl
            << "b = " << b << std::endl;
  system("pause>nul");
  return 0;
}