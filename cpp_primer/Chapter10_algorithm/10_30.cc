#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

int main() {
  istream_iterator<int> input(cin), eof;
  // 注意在输入的时候输入EOF
  vector<int> nums(input, eof);
  sort(nums.begin(), nums.end());
  vector<int> target;
  unique_copy(nums.begin(), nums.end(), back_inserter(target));
  ostream_iterator<int> output(cout, " ");
  copy(target.begin(), target.end(), output);
  system("pause>nul");
  return 0;
}
