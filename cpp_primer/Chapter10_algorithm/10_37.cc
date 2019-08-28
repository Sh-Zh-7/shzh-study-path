#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

int main() {
  vector<int> nums;
  for (size_t i = 0; i < 10; ++i) {
    nums.push_back(i);
  }
  // 返回nums[7]对应的迭代器
  // 怎么是之前一个元素的迭代器？？
  vector<int>::reverse_iterator reverse_begin(nums.begin() + 8);
  vector<int>::reverse_iterator reverse_end(nums.begin() + 3);
  for (auto i = reverse_begin; i != reverse_end; ++i) {
    cout << *i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}
