#include<iostream>
#include<string>
#include<cctype>

bool IsUpper(const std::string &str) {
// 判断是否都是大写的形式
  for (const auto &ch : str) {
    if (ch != toupper(ch)) {
      return false;
    }
  }
  return true;
}

void ToLower(std::string &str) {
// 把字符串中的字符都改为小写形式
  for (auto &ch : str) {
    ch = tolower(ch);
  }
}

int main() {
  using namespace std;
  string my_string = "Hello World!";
  string my_string_upper = "HELLOWORLD!";
  cout.setf(ios_base::boolalpha);
  cout << IsUpper(my_string) << endl;
  cout << IsUpper(my_string_upper) << endl;
  ToLower(my_string_upper);
  cout << my_string_upper << endl;
  system("pause>nul");
  return 0;
}