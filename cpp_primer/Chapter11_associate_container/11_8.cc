#include<iostream>
#include<set>
#include<vector>
using namespace std;

int main() {
  vector<int> nums;
  int num;
  while (cin >> num) {
    nums.push_back(num);
  }
  set<int> no_multi_nums(nums.cbegin(), nums.cend());
  for (int num : no_multi_nums) {
    cout << num << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}
