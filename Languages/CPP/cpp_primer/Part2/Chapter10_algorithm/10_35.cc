#include<iostream>
#include<vector>
using namespace std;

void PrintReverse(vector<int> &nums) {
  // 你要知道一个容器对象的rbegin类似于一种
  // const对象，你显然无法对其本省进行修改
  // 所以你这里i不能使用引用
  // 当然const也不行，因为你要执行++操作
  for (auto i = nums.cend(); i != nums.cbegin();) {
    cout << *(--i) << " ";
  }
  cout << endl;
  system("pause>nul");
}

int main() {
  vector<int> nums = {1, 2, 3};
  PrintReverse(nums);
  return 0;
}
