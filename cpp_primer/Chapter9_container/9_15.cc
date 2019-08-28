#include<iostream>
#include<vector>
using namespace std;

int main() {
  vector<int> v1 = {1, 2, 3};
  vector<int> v2 = {1, 3};
  vector<double> v3 = {1.0, 3.0};
  cout.setf(ios_base::boolalpha);
  cout << (v1 < v2) << endl;
  system("pause>nul");
  return 0;
}