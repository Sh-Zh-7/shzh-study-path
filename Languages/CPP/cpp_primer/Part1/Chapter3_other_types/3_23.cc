#include<iostream>
#include<vector>

int main() {
  using namespace std;
  // 输入
  int temp;
  vector<int> array;
  while (cin >> temp) {
    array.push_back(temp);
  }
  // 处理错误情况
  if (array.size() == 0) {
    cerr << "The array is empty!\n";
    system("pause");
    return -1;
  }
  vector<int> result;
  for (auto i = array.begin(); i != array.end(); ++i) {
    int mul = *i * *i;
    result.push_back(mul);
    cout << mul << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}