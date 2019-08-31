#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;

int main() {
  multimap<string, string> families;
  families.insert({"Shen", "szh"});
  families.insert({"Shen", "sjx"});
  families.insert({"Chen", "cxs"});
  for (pair<string, string> p : families) {
    cout << p.first << " : " << p.second << endl;
  }
  cout << endl;
  system("pause>nul");
  return 0;
}