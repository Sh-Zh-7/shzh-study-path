#include<iostream>
#include<forward_list>
using namespace std;

// 我现在有点明白为什么函数的声明中不能含有auto了
// 因为我是按照你的声明去找参数的匹配类型
// 而不是我传入什么实参，我的形参类型就得和它一样
void FindAndInsert(forward_list<string> &str, string target, string insertion) {
  auto i = str.cbegin(), p = str.cbefore_begin();
  for (; i != str.cend(); ++i, ++p) {
    if (*i == target) {
      str.insert_after(i, insertion);
      return;
    }
  }
  // 你要注意cend是尾后迭代器， 是指向最后一个元素后一个元素的迭代器
  // 你往它的后面差一个元素，行为是未定义的
  // 在vscode中直接是segment fault

  // 卧槽，我发现前向链表的最后一个元素真TM难访问到
  str.insert_after(p, insertion);   
}

void Print(forward_list<string> &str) {
  for (const auto &i : str) {
    cout << i << " ";
  }
  cout << endl;
}

int main() {
  forward_list<string> strings = {"qq", "wechat", "momo"};
  FindAndInsert(strings, "wechat", "xiaomi");
  Print(strings);
  FindAndInsert(strings, "szh", "zly");
  Print(strings);
  system("pause>nul");
  return 0;
}
