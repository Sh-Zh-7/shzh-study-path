#include<iostream>
#include<vector>

int main() {
  using namespace std;
  // 输入
  int temp;
  vector<int> numbers;
  while (cin >> temp) {
    numbers.push_back(temp);
  }
  // 求和
  vector<int> result;
  auto mid = numbers.begin() + (numbers.end() - numbers.begin()) / 2;
  for (auto i = numbers.begin(); i != mid; ++i) {
    auto off_size = i - numbers.begin();
    auto j = numbers[numbers.size() - off_size - 1];
    result.push_back(*i + j);
  }
  // 输出
  for (const auto &i : result) {
    cout << i << " ";
  }
  if (numbers.size() % 2 == 1) {
    cout << numbers[numbers.size() / 2];    // begin + offside是求迭代器的方法，这里直接用size的一半来整
  }
  cout << endl;
  system("pause>nul");
  return 0;
}