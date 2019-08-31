#include<iostream>
#include<string>
#include<deque>
using namespace std;

int main() {
  string temp;
  deque<string> string_deque;
  while (cin >> temp) {
    string_deque.push_back(temp);
  }
  for (auto i = string_deque.begin(); i != string_deque.end(); ++i) {
    cout << *i << endl;
  }
  system("pause>nul");
  return 0;
}
