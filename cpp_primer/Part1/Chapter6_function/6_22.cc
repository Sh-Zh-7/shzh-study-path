#include<iostream>

void Swap(int *&p1, int *&p2) {
  std::swap(p1, p2);
}

int main() {
  int a = 1;
  int b = 2;
  int *p1 = &a, *p2 = &b;
  std::cout << "Orignal:" 
            << "p1: " << p1 << ", "
            << "p2: " << p2 << std::endl;
  Swap(p1, p2);
  std::cout << "After swaping:" 
            << "p1: " << p1 << ", "
            << "p2: " << p2 << std::endl;
  system("pause>nul");
  return 0;
}