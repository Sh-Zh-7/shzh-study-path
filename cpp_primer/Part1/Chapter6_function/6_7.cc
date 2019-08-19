#include<iostream>

int Count() {
  static int count = 0;
  return ++count;
}

int main() {
  std::cout << "First: " << Count() << std::endl;
  std::cout << "Second: " << Count() << std::endl;
  std::cout << "Third: " << Count() << std::endl;
  system("pause>nul");
  return 0;
}