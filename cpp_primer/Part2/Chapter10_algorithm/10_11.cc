#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;

void RemoveDuplication(vector<string> &str) {
// 去除重复项，并按字典序排序
  sort(str.begin(), str.end());
  auto end = unique(str.begin(), str.end());
  str.erase(end, str.end());
}

// 哪怕是inline函数也可以作为谓词啊
inline bool IsShorter(const string &a, const string &b) {
// 二元谓词，赋予<号的意义
  return (a.size() < b.size()); 
} 

int main() {
  vector<string> strs = {"aa", "bb", "a", "b", "a"};
  RemoveDuplication(strs);
  stable_sort(strs.begin(), strs.end(), IsShorter);
  for (const auto &str : strs) {
    cout << str << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}
