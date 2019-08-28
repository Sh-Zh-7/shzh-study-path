#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

inline bool IsSmallerThan5(const string &s1) {
// 一元谓词，对长度小于5的指针返回true
  return (s1.size() < 5);
}

int main() {
  vector<string> words = {"Hello", "World!", "szh", "jyh"};
  auto end = partition(words.begin(), words.end(), IsSmallerThan5);
  for (auto &i = end; i != words.end(); ++i) {
    cout << *i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}
