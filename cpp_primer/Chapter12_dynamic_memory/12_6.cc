#include<iostream>
#include<algorithm>
#include<iterator>
#include<cassert>
#include<vector>
using namespace std;

void GetVector(vector<int> &v) {
  istream_iterator<int> input(cin), eof;
  copy(input, eof, back_inserter(v));
}

void PrintVector(vector<int> &v) {
  ostream_iterator<int> output(cout, " ");
  copy(v.begin(), v.end(), output);
  cout << endl;
}

void SafeFreeVector(vector<int> *&p) {
 // assert(p);
  // 个人认为这里没有必要进行assert
  free(p);
  p = nullptr;
}

int main() {
  vector<int> *p_v = new (nothrow) vector<int>;
  GetVector(*p_v);
  PrintVector(*p_v);
  SafeFreeVector(p_v);
  system("pause>nul");
  return 0;
}
