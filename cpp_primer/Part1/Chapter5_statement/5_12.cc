#include<iostream>
#include<string>

int main() {
  using std::cout;
  using std::endl;
  using std::getline;
  std::string temp;
  // 注意getline返回的也是istream对象
  while (getline(std::cin, temp)) {
    unsigned ff_count = 0, fl_count = 0, fi_count = 0;
    for (const auto &ch : temp) {
      if (ch == 'f') {
        // 注意getline和cin.get()的搭配简直是shit!!
        char next_cin = std::cin.get();
        switch (next_cin) {
          case 'f':
            ++ff_count; break;
          case 'l':
            ++fl_count; break;
          case 'i':
            ++fi_count; break;
          default:
            break;
        }
      }
    }
    cout << "The count of ff is: " << ff_count << endl; 
    cout << "The count of fl is: " << fl_count << endl;
    cout << "The count of fi is: " << fi_count << endl;
  }
  system("pause>nul");
  return 0;  
}