#include<iostream>
#include<cstring>

int main() {
  using namespace std;
  constexpr int kSize = 100;
  char s1[kSize];
  char s2[kSize];
  // 注意gets和getline对于\n的两个处理一模一样
  gets(s1);
  gets(s2); 
  char s3[kSize * 2];
  strcpy(s3, s1);
  strcat(s3, s2);
  cout << s3 << endl;
  system("pause>nul");
  return 0;
}