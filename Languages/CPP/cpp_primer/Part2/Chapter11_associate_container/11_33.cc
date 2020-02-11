#include<string>
#include<fstream>
#include<sstream>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

#define work_dir ".\\Chapter11_associate_container"

template<typename T>
void Print(T &x) {
// 通过答应x的数据查看容器的正确性
  for (const auto &i : x) {
    cout << i.first << " : " << i.second << endl;
  }
  system("pause");
}

const string ParseWord(string &word, unordered_map<string, string> &trans) {
// 根据trans中的规则转换word
  if (trans.find(word) != trans.cend()) {
    auto iter = trans.find(word);
    return iter->second;
  }
  return word;
}

unordered_map<string, string> GetTrans(ifstream &infile) {
// 从一个指定文件中读取转换规则
  unordered_map<string, string> result;
  string target_word, line;
  while (infile >> target_word && getline(infile, line)) {
    result[target_word] = line.substr(1);
  }
  return result; 
}

void Pocess() {
// 将我们的目标语句全部变为转化后的语句
  // 先读取文件
  ifstream trans_file(work_dir "\\rule_of_transform.txt");    
  ifstream source(work_dir "\\source.txt");
  ofstream target(work_dir "\\target.txt");
  unordered_map<string, string> trans = GetTrans(trans_file);
  Print(trans);
  // 对每一行进行处理
  string line;
  while (getline(source, line)) {
    istringstream temp(line);
    string word;
    // 对一行中的每个单词进行处理
    while (temp >> word) {
      target << ParseWord(word, trans) << " "; 
    }
    target << endl;
  } 
}

int main() {
  Pocess();
  return 0;
}