#include<iostream>
#include<vector>

int main() {
  using namespace std;
  // 声明
  constexpr int kSize = 10;
  vector<int> array(10, 0);
  int a[kSize];
  // 赋值
  auto p = array.cbegin();
  for (auto &i : a) {
    i = *p;
    ++p;
  }
  // 输出
  for (const auto &i : a) {
    cout << i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}