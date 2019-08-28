#include<iostream>
#include<iterator>
#include<algorithm>
#include<list>
using namespace std;

void DeDuplication(list<int> &li) {
  li.sort();
  li.unique();
}

int main() {
  list<int> li = {1, 1, 5, 5, 5, 2, 4, 3, 3};
  DeDuplication(li);
  ostream_iterator<int> output(cout, " ");
  copy(li.begin(), li.end(), output);
  cout << endl;
  system("pause>nul");
  return 0;
}
