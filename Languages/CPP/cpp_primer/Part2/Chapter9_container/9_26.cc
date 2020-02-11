#include<iostream>
#include<iterator>
#include<vector>
#include<list>
using namespace std;

int main() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  // 你要知道原生数组是不能直接赋给vector和list对象的
  // 所以要引入iterator的头文件，使用非成员函数来获得迭代器
  vector<int> v(begin(ia), end(ia));
  list<int> l(begin(ia), end(ia));

  // 利用erase成员函数的返回值来进行迭代
  auto iter_of_i = v.begin();
  while (iter_of_i != v.end()) {
    if (!(*iter_of_i & 0x1)) {
      iter_of_i = v.erase(iter_of_i);
    } else {
      ++iter_of_i;
    }
  }

  auto iter_of_l = l.begin();
  while (iter_of_l != l.end()) {
    if (*iter_of_l & 0x1) {
      iter_of_l = l.erase(iter_of_l);
    } else {
      ++iter_of_l;
    }
  }

  for (const auto &num : v) {
    cout << num << " ";
  }
  cout << endl;
  for (const auto &num : l) {
    cout << num << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}