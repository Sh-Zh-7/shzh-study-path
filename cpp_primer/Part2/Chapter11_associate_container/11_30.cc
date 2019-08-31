#include<iostream>
#include<map>
#include<string>
using namespace std;

void FindAndErase(multimap<string, string> &mm, const string &str) {
  auto range = mm.equal_range(str);
  if (range.first == range.second) {
    cout << "没有可以删除的元素！\n";
  } else {
    mm.erase(range.first, range.second);
  }
}

void Print(multimap<string, string> &x) {
  for (const auto &i : x) {
    cout << i.first << " : " << i.second << endl; 
  }
}

int main() {
  multimap<string, string> books;
  // 注意multimap不支持下标运算符，因为可能有多个关键字匹配
  books.insert({"szh", "aaa"});
  books.insert({"szh", "bbb"});
  books.insert({"sjx", "ccc"});
  books.insert({"cxs", "ddd"});
  FindAndErase(books, "szh");
  Print(books);
  system("pause>nul");
  return 0;
}
