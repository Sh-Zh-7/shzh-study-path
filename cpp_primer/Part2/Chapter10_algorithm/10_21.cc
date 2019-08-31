#include<iostream>

int main() {
  using namespace std;
  int x = 3;
  auto f = [&x]() -> bool { if (x) --x; else return false; return true; };
  f();  cout << x << endl;
  f();  cout << x << endl;
  f();  cout << x << endl;
  system("pause>nul");
  return 0;
}