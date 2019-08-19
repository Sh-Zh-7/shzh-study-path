#include<iostream>
#include<vector>

int sum(int a, int b) { return a + b; }

int mius(int a, int b) { return a - b; }

int multiply(int a, int b) { return a * b; }

int divide(int a, int b) { return a / b; }

// using是把你定义的类型别名放在等号的左侧
using Fun = decltype(sum);

int main() {
  using namespace std;
  vector<Fun *> list_of_fun;
  list_of_fun.push_back(sum);
  list_of_fun.push_back(mius);
  list_of_fun.push_back(multiply);
  list_of_fun.push_back(divide);
  cout << list_of_fun[0](1, 2) << endl;
  cout << list_of_fun[1](1, 2) << endl;
  cout << list_of_fun[2](1, 2) << endl;
  cout << list_of_fun[3](2, 1) << endl;
  system("pause>nul");
  return 0;
}


