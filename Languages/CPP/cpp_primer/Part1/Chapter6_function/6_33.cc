#include<iostream>
#include<vector>

void Print(std::vector<int> v) {
  if (v.begin() == v.end()) {
    return;
  }
  // 输出第一个元素
  std::cout << v[0] << std::endl;
  // 利用已有的vector构造出新的vector
  Print({v.begin() + 1, v.end()});
}

int main() {
  using namespace std;
  vector<int> my_list {1, 2, 3, 4, 5};
  Print(my_list);
  system("pause>nul");
  return 0;
}
