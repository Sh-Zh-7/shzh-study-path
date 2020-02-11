#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main() {
  list<int> nums = {4, 5, 6, 0, 7};
  auto target = find(nums.crbegin(), nums.crend(), 0);
  if (target != nums.crend()) {
    cout << "The index is: " << distance(nums.cbegin(), (++target).base()) << endl;
  } else {
    cout << "Not found!\n";
  }
  system("pause>nul");
  return 0;
}
