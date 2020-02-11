#include<iostream>
#include<sstream>
#include<string>

std::istringstream &ReadAndPrint(std::istringstream &in) {
  using std::cout;
  using std::endl;  // 你以为endl是什么所谓的manipulator?其实人家是一个函数
  using std::string;
  string temp;
  while (in >> temp) {
    cout << temp << endl;
  }
  return in;
}

int main() {
  using namespace std;
  string content;
  getline(cin, content);
  istringstream my_string_stream(content);
  ReadAndPrint(my_string_stream);
  system("pause>nul");
  return 0;
}
