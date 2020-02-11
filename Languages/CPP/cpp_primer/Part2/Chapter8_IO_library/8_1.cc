#include<iostream>
using std::cin;
using std::cout;
using std::endl;

void Read(std::istream &is) {
  auto old_state = is.rdstate();
  while (!is.eof()) {
    char ch = is.get();
    cout << ch;
  }
  is.setstate(old_state);
}

int main() {
  Read(cin);
  int test;
  cin >> test;
  cout << test << endl;
  system("pause>nul");
  return 0;
}