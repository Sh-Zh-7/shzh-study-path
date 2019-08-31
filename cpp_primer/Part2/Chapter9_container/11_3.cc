#include<iostream>
#include<map>
#include<set>
#include<iterator>
#include<algorithm>
#include<cctype>
using namespace std;

inline string ToLower(string &str) {
  string result;
  transform(str.begin(), str.end(), back_inserter(result),
       [](char &ch) -> char { if (!islower(ch)) return tolower(ch); return ch; });
  return result;
}

int main() {
  map<string, size_t> word_count;
  set<string> exclude = {"The", "And", "Or", "a"};
  string word;
  while (cin >> word) {
    // 如果你所读入的字符并不在你的exclude集合中
    // 就添加到我的dict中去
    if (exclude.find(word) == exclude.end()) {
      ++word_count[ToLower(word)];
    }
  }
  for (auto word_pair : word_count) {
    cout << word_pair.first << " : " 
         << word_pair.second << endl; 
  }
  system("pause>nul");
  return 0;
}
