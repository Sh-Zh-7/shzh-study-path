#include<iostream>
#include<string>

int main() {
  using namespace std;
  // 注意这个freopen是相对于你编译器设置的地址而言的
  // 所以一定要输入正确的地址
  freopen(R"(.\Chapter5_statement\5_19.in)", "r", stdin);
  freopen(R"(.\Chapter5_statement\5_19.out)", "w", stdout);
  do {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1.size() > s2.size()) {
      cout << s2 << endl;
    } else if (s1.size() < s2.size()) {
      cout << s1 << endl;
    } else {
      cout << "Equal!\n";
    }
  } while (cin);
  // 不管是模拟EOF还是真实文件的EOF都无法解决一个问题
  // 那就是最后输入EOF时，两个字符串均为空，必然输出“Equal”
  // 这就说明了do...while的劣势
  system("pause>nul");
  return 0;
}
