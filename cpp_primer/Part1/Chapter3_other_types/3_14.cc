#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main() {
  int temp;
  vector<int> my_array;
  while (cin >> temp) {
    my_array.push_back(temp);
  }
  // 注意这里使用const auto&是最好的
  for (const auto &i : my_array) {
    cout << i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}