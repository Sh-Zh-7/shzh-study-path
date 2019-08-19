#include<iostream>
#include<iterator>
#include<cstring>
#include<vector>

int main() {
  using namespace std;
  constexpr int kSize = 10;
  int a[kSize];
  for (size_t i = 0; i < kSize; ++i) {
    a[i] = i;
  }
  int b[kSize];
  // 复制原生数组
  memcpy(b, a, sizeof(a));
  for (size_t i = 0; i < kSize; ++i) {
    cout << b[i] << " ";
  }
  cout << endl;
  // 利用vector重做一遍
  vector<int> array(begin(a), end(a));
  auto len = array.size();
  for (decltype(array.size()) i = 0; i < len; ++i) {
    cout << array[i] << " ";
  }
  cout << endl;
  vector<int> array2 = array;
  for (auto i = array2.cbegin(); i != array2.cend(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}