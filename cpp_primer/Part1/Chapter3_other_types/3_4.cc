#include<iostream>
#include<string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// 判断字符串的大小（字典序）
// int main() {
//   using std::getline;
//   string s1, s2;
//   getline(cin, s1);
//   getline(cin, s2);
//   if (s1 == s2) {
//     cout << s1 << " == " << s2 << endl;
//   } else {
//     // 输出两者之间较大的字符串的时候
//     // 很自然的想法就是使用三元运算符?
//     // 然而这个唯一的三元运算符是不能被重载的
//     if (s1 > s2) {
//       cout << s1 << " > " << s2 << endl;
//     } else {
//       cout << s1 << " < " << s2 << endl;
//     }
//   }
//   system("pause>nul");
//   return 0;
// }

int main() {
// 判断字符串的长度
  using std::getline;
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  // 其实储存.size()返回值类型也可以使用int
  // 不过为了专业起见还是使用auto把。
  int length_of_s1 = s1.size();
  int length_of_s2 = s2.size();
  if (length_of_s1 > length_of_s2) {
    cout << "length of " << s1 << " > " << s2;
  } else if (length_of_s1 == length_of_s2) {
    cout << "length of " << s1 << " == " << s2;
  } else {
    cout << "length of " << s1 << " < " << s2;
  }
  cout << endl;
  system("pause>nul");
  return 0;
}