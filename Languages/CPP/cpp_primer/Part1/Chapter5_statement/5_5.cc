#include<iostream>
#include<vector>
#include<string>

int main() {
  using std::cin;
  using std::cout;
  using std::endl;
  using std::vector;
  using std::string;
  const vector<string> grade = {"F", "D", "C", "B", "A", "A++"};
  int temp;
  while (cin >> temp) {
    if (temp == 100) {
      cout << "A++" << endl;
      continue;
    } else if (temp < 60) {
      cout << "F" << endl;
      continue;
    }
    string grade_temp = grade[(temp - 50) / 10];
    int last_number = temp % 10;
    if (last_number >= 8) {
      grade_temp += "+";
    } else if (last_number <= 2) {
      grade_temp += "-";
    }
    cout << grade_temp << endl;
  }
  system("pause>nul");
  return 0;
}