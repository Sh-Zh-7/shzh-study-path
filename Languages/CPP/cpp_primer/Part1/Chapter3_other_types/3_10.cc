#include<iostream>
#include<string>
#include<cctype>

int main() {
  using namespace std;
  string temp;
  getline(cin, temp);
  for (auto &c : temp) {
    if (ispunct(c)) {
      c = ' ';
    }
  }
  cout << temp << endl;
  system("pause>nul");
  return 0;
}