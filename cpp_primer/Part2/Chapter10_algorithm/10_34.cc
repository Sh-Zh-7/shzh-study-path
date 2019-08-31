#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;

void PrintReverse(vector<int> &nums) {
// 利用流迭代器倒序打印
  ostream_iterator<int> output(cout, " ");
  copy(nums.rbegin(), nums.rend(), output);
  cout << endl;   // 最后再补一个换行符
  system("pause>nul");
}

int main() {
  vector<int> nums = {1, 2, 3};
  PrintReverse(nums);
  return 0;
}
