#include<iostream>
#include<stdexcept>

int main() {
  using namespace std;
  int a, b;
  cin >> a >> b;
  if (b == 0) {
    throw runtime_error("除数不能为0");
    system("pause>nul");
  }
  cout << a / b << endl;
  system("pause>nul");
  return 0;
}