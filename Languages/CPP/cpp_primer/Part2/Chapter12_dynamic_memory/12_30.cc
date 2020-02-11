#include"query.h"
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

void RunQuery(ifstream &infile) {
  TextQuery my_query(infile);
  while (true) {
    cout << "Please input your choice(q to quit):\n";
    string choice;
    cin >> choice;
    if (choice != "q") {
      // 不知道为什么，这里不能传入临时变量
      // 可能和移动语义有点关系吧，我不太懂
      cout << my_query.Query(choice);
    } else {
      break;
    }
  }
}

int main() {
  constexpr char s[] = ".\\test.in";
  ifstream infile(s);
  if (!infile) {
    cerr << "Can't open file!\n";
    exit(EXIT_FAILURE);
  }
  RunQuery(infile);
  system("pause>nul");
  return 0;
}