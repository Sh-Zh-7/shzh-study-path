#include<iostream>

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  char ch;
  unsigned a_count = 0;
  unsigned e_count = 0;
  unsigned i_count = 0;
  unsigned o_count = 0;
  unsigned u_count = 0;

  while (cin >> ch) {
  // switch后面不需要直接加: 用{}
  // case后面需要使用:——这也是C++少数需要使用:的地方
    switch (ch) {
      case 'a':
        ++a_count; break;
      case 'e':
        ++e_count; break;
      case 'i':
        ++i_count; break;
      case 'o':
        ++o_count; break;
      case 'u':
        ++u_count; break;
      default: break;
    }
  }
  cout << "count_of_a:" << a_count << endl;
  cout << "count_of_e:" << e_count << endl;
  cout << "count_of_i:" << i_count << endl;
  cout << "count_of_o:" << o_count << endl;
  cout << "count_of_u:" << u_count << endl;
  system("pause>nul");
  return 0;
}