#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>

int main() {
  using namespace std;
  vector<int> li;
  fill_n(back_inserter(li), 5, 0);
  // fill_n(li.cbegin(), 5, 0);
  for (const auto &i : li) {
    cout << i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}
