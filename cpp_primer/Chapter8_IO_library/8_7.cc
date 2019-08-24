#include<fstream>
#include<iostream>

int main() {
  using namespace std;
  int test;
  ofstream ofile("2.txt");
  cin >> test;
  ofile << test;
  if (!ofile) {
    cerr << "Failed!\n";
    system("pause>nul");
    return -1;
  }
  ofile.close();

  return 0;
}