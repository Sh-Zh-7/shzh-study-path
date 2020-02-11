#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int Count(vector<string> &strs, size_t n) {
  return count_if(strs.begin(), strs.end(), [n](const string &str){ return str.size() > n; });
}

int main() {
  vector<string> strs = {"Hello", "World", "szh", "zly"};
  cout << Count(strs, 4) << endl;
  system("pause>nul");
  return 0;
}