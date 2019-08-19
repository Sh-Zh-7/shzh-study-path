#include<iostream>
#include<vector>
using namespace std;

int main() {
  int temp;
  vector<int> numbers;
  while (cin >> temp) {
    numbers.push_back(temp);
  }
  // 求和
  for (auto i = numbers.begin(); i < numbers.end() - 1; i += 2) {
    cout << *i + *(i + 1) << " ";
  }
  if (numbers.size() % 2 == 1) {
    cout << numbers[numbers.size() - 1] << endl;
  }
  system("pause>nul");
  return 0;
}