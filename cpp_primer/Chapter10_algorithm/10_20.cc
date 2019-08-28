#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main() {
  vector<string> words = {"Hello!", "World!", "love", "szh"};
  int num = count_if(words.begin(), words.end(), 
              [](const string &str) { return str.size() >= 6; });
  cout << num << endl;
  system("pause>nul");
  return 0;
}
