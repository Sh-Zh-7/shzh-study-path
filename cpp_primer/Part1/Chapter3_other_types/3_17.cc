#include<iostream>
#include<vector>
#include<string>
#include<cctype>

int main() {
  using namespace std;
  string temp;
  vector<string> words;
  while (cin >> temp) {
    words.push_back(temp);
  } 
  for (auto &word : words) {
    for (auto &ch : word) {
      ch = toupper(ch);
    }
  }
  // Observing words
  for (const auto &word : words) {
    cout << word << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}