#include<iostream>

int main() {
  using namespace std;
  int a = 1;
  auto f = [a](int b) { return a + b;};
  cout << f(1) << endl;
  system("pause>nul");
  return 0;
}
