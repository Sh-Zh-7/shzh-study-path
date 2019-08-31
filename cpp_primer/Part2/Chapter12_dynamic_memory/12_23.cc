#include<iostream>
#include<cstring>
#include<string>

int main() {
  using namespace std;
  // 连接char
  constexpr char s1[] = "Hello ";
  constexpr char s2[] = "World!";
  char *s = new char[sizeof(s1) + sizeof(s2)];
  strncpy(s, s1, sizeof(s1));
  // s + sizeof(s1) - 1恰好是s1中最后一个字符——空字符的位置
  strncpy(s + sizeof(s1) - 1, s2, sizeof(s2));
  cout << s << endl;
  delete [] s;

  // constexpr只能用于char数组，而不能用于string类型的初始化
  const string str1 = "Goodbye ";
  const string str2 = "World!";
  string *str = new string;
  *str += (str1 + str2);
  cout << *str << endl;
  delete str;

  // 从上面两个例子的对比中我们不难看出string的使用明显优于char数组
  system("pause>nul");
  return 0;
}
