#include<iostream>
#include<vector>

int main() {
  std::vector<int> vector1;
  std::vector<int> vector2;
  // 输入
  int temp;
  while (std::cin >> temp) {
    vector1.push_back(temp);
  } 
  std::cin.clear();
  std::cin.sync();
  while (std::cin >> temp) {
    vector2.push_back(temp);
  }
  // 处理
  auto size = (vector1.size() < vector2.size())? vector1.size() : vector2.size();
  for (decltype(size) i = 0; i < size; ++i) {
    if (vector1[i] != vector2[i]) {
      std::cout << "No!\n";
      system("pause>nul");
      return 0;
    } 
  } 
  std::cout << "Yes!\n";
  system("pause>nul");
  return 0;
}