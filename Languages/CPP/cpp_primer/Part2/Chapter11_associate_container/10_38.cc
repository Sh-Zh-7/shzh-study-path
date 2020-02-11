#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

int main() {
  unordered_map<string, int> word_count;
  string word;
  while (cin >> word) {
    ++word_count[word];
  }
  for (const auto &wc : word_count) {
    cout << wc.first << " : " << wc.second << endl;
  }
  system("pause>nul");
  return 0;
}
