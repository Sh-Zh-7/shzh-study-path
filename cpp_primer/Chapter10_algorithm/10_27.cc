#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

void DeDup(vector<int> &nums, vector<int> &target) {
// 使用back_inserter把目的序列拷贝到空的容器中
  sort(nums.begin(), nums.end());
  unique_copy(nums.begin(), nums.end(), back_inserter(target));
}

int main() {
  vector<int> nums, target;
  nums = {1, 1, 2, 2, 5, 4, 4, 4};
  DeDup(nums, target);
  for_each(target.begin(), target.end(), [](int n){ cout << n << " "; });
  system("pause>nul");
  return 0;
}
