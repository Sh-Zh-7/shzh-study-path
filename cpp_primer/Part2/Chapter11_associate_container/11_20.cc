#include<map>
#include<string>
#include<iostream>
using namespace std;

int main() {
  string word;
  map<string, int> word_count;
  while (cin >> word) {
    ++word_count.insert({word, 0}).first->second;
  }
  for (const auto &p : word_count) {
    cout << p.first << " : " << p.second << endl;
  }
  system("pause>nul");
  return 0;
}
