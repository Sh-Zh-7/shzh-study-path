#include<string>
#include<vector>
#include<utility>
#include<iostream>
using namespace std;

int main() {
  vector<pair<string, int>> ve;
  // 这里就不应该使用cin.fail
  // 而是应该把输入和判断结合，当作condition使用
  while (!cin.fail()) {
    string str;
    int val;    // 原来内置类型的那个词被当作关键字看的，怪不得和其它类别的不一样
    cin >> str >> val;
    pair<string, int> temp = {str, val};
    ve.push_back(temp);
  }
  for (const auto &p : ve) {
    cout << p.first << " : " << p.second << endl;
  }
  system("pause>nul");
  return 0;
}
