#include<iostream>
#include<vector>
#include<string>

int main() {
  using namespace std;
  string before_string;
  string now_string;
  int count = 0;
  while (cin >> now_string) {
    if (before_string == "") {
      count = 1;
    } else if (before_string == now_string) {
      ++count;
    } else if (before_string != now_string) {
      cout << before_string << " : " << count << endl;
      count = 1;
    }
    before_string = now_string;
  } 
  cout << now_string << " : " << count << endl;
  system("pause>nul");
  return 0;
}