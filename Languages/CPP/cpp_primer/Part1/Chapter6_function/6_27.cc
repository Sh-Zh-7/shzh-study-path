#include<iostream>
#include<initializer_list>
// 注意这个initializer_list是定义在标准库中的
// 所以也在标准命名空间中

int Sum(std::initializer_list<int> my_list) {
  int sum = 0;
  for (auto &number : my_list) {
    // 注意initializer_list里面的元素都是常数值
    sum += number;
  }
  return sum;
}

int main() {
  using namespace std;
  // 我这里的用{}的narowing是直接报错了的
  int x = 1;
  cout << Sum({1, 2, x}) << endl;
  cout << Sum({9, 8, 7, 6}) << endl;
  system("pause>nul");
  return 0;
}
