#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void ElimDups(vector<string> &str) {
  sort(str.begin(), str.end());
  auto end = unique(str.begin(), str.end());
  str.erase(end, str.end());
}

int main() {
  vector<string> strs = {"a", "a", "c", "b", "b", "d"};
  ElimDups(strs);
  for (const auto &str : strs) {
    cout << str << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}
