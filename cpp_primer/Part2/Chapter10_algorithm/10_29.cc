#include<iostream>
#include<fstream>
#include<iterator>
#include<vector>
#include<string>
using namespace std;

void Read(const string &filename, vector<string> &target) {
  ifstream file(filename);
  // 文件打开失败，failbit会被置位
  // 这时候就可以通过fail来检测
  if (file.fail()) {
    // 比如打开一个根本就不存在的文件，我的failbit就会被置位
    cerr << "Cann't open file " << filename << endl;
    system("pause>nul");
    exit(EXIT_FAILURE);
  } 
  // 注意引入头文件iterator和使用模板
  istream_iterator<string> iter_file(file), iter_end;
  target.assign(iter_file, iter_end);
  // 虽然说file脱离它的作用域后生命周期就结束了
  // 但是直接调用close绝对是一个好的方法
  file.close(); 
}

int main() {
  vector<string> target;
  // 这里是直接使用输出参数了
  Read("./Chapter10_algorithem/1.txt", target);
  ostream_iterator<string> output(cout, "\n");
  // for (auto &str : target) {
  //   output = str;
  // }
  copy(target.begin(), target.end(), output);
  // 不知道为何，你这里直接写道cout流中
  // 就可以直接输出了
  system("pause>nul");
  return 0;
}