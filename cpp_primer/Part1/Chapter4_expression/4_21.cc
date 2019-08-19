#include<iostream>
#include<vector>

int main() {
  using namespace std;
  int temp;
  vector<int> array;
  while (cin >> temp) {
    array.push_back(temp);
  }
  for (auto &number : array) {
    if (number % 2 == 1) {
      number *= 2;
    }
  }
  for (const auto &number: array) {
    cout << number << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}