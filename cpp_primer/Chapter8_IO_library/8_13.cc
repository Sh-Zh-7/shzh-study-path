#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;

struct Person {
  string name_;
  vector<string> phone_;
};

int main(int argc, char *argv[]) {
  ifstream ifile(argv[1]);
  vector<Person> people;
  if (!ifile) {
    cerr << "Cann't open file!\n";
    system("pause>nul");
    return -1;
  }
  // 从文件中读入信息
  // 和从标准输入中读取大同小异
  string line, word;
  // 对于vector的处理，这里采用的是临时变量的方法
  // 先做好临时变量，然后把我们的临时变量push_back进我们的vector中
  while (getline(ifile, line)) {
    istringstream recode(line);
    Person temp;
    recode >> temp.name_;
    while (recode >> word) {
      temp.phone_.push_back(word);
    }
    people.push_back(temp);
  }

}