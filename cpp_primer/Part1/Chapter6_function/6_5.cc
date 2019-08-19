#include<iostream>
#include<cmath>

template<typename T>
inline T MyAbs(T x) {
  using std::fabs;
  return fabs(x);
}

int main() {
  int n;
  std::cin >> n;
  std::cout << MyAbs(n) << std::endl;
  system("pause>nul");
  return 0;
}