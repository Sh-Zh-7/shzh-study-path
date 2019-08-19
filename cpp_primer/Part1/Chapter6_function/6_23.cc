#include<iostream>

void Print(int x) {
  std::cout << x << std::endl;
}

void Print(const int (&a)[2]) {
  for (const auto &x : a) {
    std::cout << x << " ";
  }
  std::cout << std::endl;
}

int main() {
  int i = 0, j[2] = {0, 1};
  Print(i);
  Print(j);
  system("pause>nul");
  return 0;
}