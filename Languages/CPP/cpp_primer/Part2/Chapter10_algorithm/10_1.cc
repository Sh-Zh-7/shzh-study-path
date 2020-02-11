#include<iostream>
#include<algorithm>
#include<vector>

int main() {
  using namespace std;
  vector<int> li = {1, 2, 2, 3};
  auto count_1 = count(li.cbegin(), li.cend(), 1);
  cout << count_1 << endl;
  auto count_2 = count(li.cbegin(), li.cend(), 2);
  cout << count_2 << endl;
  auto count_4 = count(li.begin(), li.end(), 4);
  cout << count_4 << endl;
  system("pause>nul");
  return 0;
}
