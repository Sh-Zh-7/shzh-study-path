#include<iostream>
#include<string>

int main() {
  using namespace std;
  string temp;
  getline(cin, temp);
  for (char& c : temp) {
    c = 'X';
  }
  cout << temp << endl;
  system("pause>nul");
  return 0;
}