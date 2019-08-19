#include<iostream>
#include<string>

int main() {
  int temp;
  while (std::cin >> temp) {
    std::string grade;
    // 多层ternary，使用换行增加可读性
    grade =  (temp > 90)? "High pass" 
                : (temp > 75)? "Pass"
                : (temp > 60)? "Low pass": "fail";
    std::cout << grade << std::endl;
  }
  system("pause>nul");
  return 0;
}