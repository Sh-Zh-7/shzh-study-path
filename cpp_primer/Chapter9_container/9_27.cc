#include<iostream>
#include<forward_list>
using namespace std;

int main() {
  forward_list<int> fl = {5, 3, 1, 4, 2};
  auto prev = fl.before_begin();
  auto curr = fl.begin();
  // 进行元素删除的时候要进行特殊的处理
  // 不然很可能会陷入死循环
  while (curr != fl.end()) {
    if (*curr & 0x1) {
      // 由于删除的节点就是curr指向的节点
      // 所以这里要迅速给curr赋值
      // 同时你要注意这里的curr和prev其实都已经更新到最新的状态了
      curr = fl.erase_after(prev);
    } else {
      prev = curr;
      ++curr;
    }
  } 
  for (const auto &i : fl) {
    cout << i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}
