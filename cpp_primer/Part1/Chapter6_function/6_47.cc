#include<iostream>
#include<vector>
#include<cassert>

// 不能再全局(所有函数之外)使用using namespace的坏处：
// 就是在写函数特征标的时候特别吃亏
// （虽然可以通过using声明完美解决）
void Print(std::vector<int> my_vector, size_t n) {
// 尾递归打印vector的值
  if (n == my_vector.size()) {
    return;
  }
#ifndef NDEBUG
#define NDEBUG
  std::cout << "The size of my vector is: " << my_vector.size() << std::endl;
#endif 
  std::cout << my_vector[n] << std::endl;
  Print(my_vector, n + 1);
} 

int main() {
  using namespace std;
  vector<int> my_vector{1, 2, 3};
  Print(my_vector, 0);
  system("pause>nul");
  return 0;
}