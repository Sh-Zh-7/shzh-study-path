#include<iostream>
#include<cstring>
#include<stdexcept>

int main() {
  using namespace std;

  constexpr size_t kSize = 6;
  char ch;
  char *p = new char[kSize];
  size_t index = 0;
  // 由于这里是读取字符，所以最好是cin.get()
  while (cin >> ch) {
    if (index < kSize) {
      p[index++] = ch;
    } else {
      throw out_of_range("Only support 6 characters!\n");
    }
  }
  system("pause>nul");
  return 0; 
}
