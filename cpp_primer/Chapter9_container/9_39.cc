#include<vector>
#include<iostream>
using namespace std;

int main() {
  vector<int> ints;
  ints.reserve(1024);
  cout << ints.capacity() << endl;
  cout << sizeof(ints) << endl;
  
  vector<double> doubles;
  doubles.reserve(1024);
  cout << doubles.capacity() << endl;
  cout << sizeof(doubles) << endl;
  system("pause>nul");
  return 0; 
}