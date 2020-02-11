#include<iostream>
#include<string>
using namespace std;

int main() {
  string temp;
  // cin遇到EOF，直接错误退出
  // 不像scanf，还要专门检测EOF退出
  while (cin >> temp) {
  }
  return 0;
}