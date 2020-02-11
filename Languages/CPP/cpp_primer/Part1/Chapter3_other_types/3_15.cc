#include<iostream>
#include<vector>
#include<string>

int main() {
  using namespace std;
  string temp;
  vector<string> my_array;
  while (cin >> temp) {
    my_array.push_back(temp);
  }
  // Observing时使用const auto&
  for (const auto &i : my_array) {
    cout << i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}