#include<iostream>
#include<list>
#include<string>
#include<vector>

int main() {
  using namespace std;
  list<char *> li_of_ch;
  vector<string> vector_of_string;
  li_of_ch = {"He", "llo", "Wo", "rld!"};
  vector_of_string.assign(li_of_ch.begin(), li_of_ch.end());
  for (const auto &str : vector_of_string) {
    cout << str << endl;
  }
  system("pause>nul");
  return 0;
}