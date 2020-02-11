#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
  vector<string> strs = {"Hello", "World"};
  cout << count(strs.cbegin(), strs.cend(), "Hello") << endl;
  cout << count(strs.cbegin(), strs.cend(), "Wrold") << endl;
  system("pause>nul");
  return 0;
}
