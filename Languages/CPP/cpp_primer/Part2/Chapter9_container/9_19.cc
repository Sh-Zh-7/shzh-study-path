#include<iostream>
#include<string>
#include<list>
using namespace std;

int main() {
  string temp;
  list<string> li_of_str;
  while (cin >> temp) {
    li_of_str.push_back(temp);
  }
  for (auto i = li_of_str.cbegin(); i != li_of_str.cend(); ++i) {
    cout << *i << endl;
  }
  system("pause>nul");
  return 0;
}
