#include<iostream>

int Fact(int n) {
  int result = 1;
  for (int i = 1; i <= n; ++i) {
    result *= i;
  } 
  return result;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << Fact(n) << std::endl;
  system("pause>nul");
  return 0;
}