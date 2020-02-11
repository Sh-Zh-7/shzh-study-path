#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// vscode注释：ctrl+k, ctrl+c
// int main() {
// // 一次读入一整行
//   using std::getline;
//   string temp;
//   while (getline(cin, temp)) {
//     // 判断是否为空，这样我们输入空行的时候只会往下移一行
//     if (!temp.empty()) {
//       // getline读取\n，但不保留在temp中
//       cout << temp << endl;
//     }
//   }  
//   system("pause>nul");
//   return 0;
// }

int main() {
  string temp;
  while (cin >> temp) {
    if (!temp.empty()) {
      cout << temp << endl;
    }
  }
  system("pause>nul");
  return 0;
}