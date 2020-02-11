#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;

int main() {
  map<string, vector<string>> families;
  families["Shen"].push_back("sjx");
  families["Shen"].push_back("szh");
  families["Chen"].push_back("cxs");
  for (const auto &p : families) {
    for (const auto &person : p.second) {
      cout << p.first << " : " << person << endl;
    }
  }
  system("pause>nul");
  return 0;
}
