#include<iostream>
#include<memory>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;

void GetVector(shared_ptr<vector<int>> p) {
  istream_iterator<int> input(cin), eof;
  copy(input, eof, back_inserter(*p));
}

void PrintVector(shared_ptr<vector<int>> p) {
  ostream_iterator<int> output(cout, " ");
  copy(p->begin(), p->end(), output);
  cout << endl;
}

int main() {
  shared_ptr<vector<int>> p =  make_shared<vector<int>>();
  GetVector(p);
  PrintVector(p);
  system("pause>nul");
  return 0;
}
