#include<iostream>
#include<numeric>
#include<vector>
using namespace std;

int main() {
  vector<int> li = {1, 2, 3, 4, 5};
  cout << accumulate(li.cbegin(), li.cend(), 0);
  system("pause>nul");
  return 0;
}
