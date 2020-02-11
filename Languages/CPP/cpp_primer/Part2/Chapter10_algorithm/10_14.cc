#include<iostream>

int main() {
  using namespace std;
  auto f = [](int a, int b){ return a + b; };
  cout << f(1, 1) << endl;
  system("pause>nul");
  return 0;
}