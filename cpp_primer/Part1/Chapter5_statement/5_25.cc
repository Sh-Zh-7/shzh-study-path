#include<iostream>
#include<stdexcept>
#include<cctype>

int main() {
  using namespace std;
  int a, b;
  while (cin >> a >> b) {
    try {
      if (b == 0) {
        // 注意在throw中必须自定义error
        throw runtime_error("The division can't be zero!");
      }
      cout << a / b << endl;
    } catch(runtime_error err) {
      cout << err.what() 
          << "\nWant to try again?(y for yes, n for no)\n";
      cin.get();    // 吸收缓冲区残留下来的\n
      // 第一次在condition中使用init-statement
      // 感觉这个可以与while(true)+相应语句 来替换
      // 另外这里直接return，感觉也不太好，万一退出后还有模块呢
      // 这个感觉有点难搞，以后写小游戏的时候再看看
      while (char choice = cin.get()) {
        if (tolower(choice) == 'y') {
          break;
        } else if (tolower(choice) == 'n') {
          return 0; 
        } else {
          cout << "Please input y or n!\n";
        }
      }
    }
  }
  system("pause>nul");
  return 0;
}