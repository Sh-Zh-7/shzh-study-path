#include<iostream>
#include<vector>
using namespace std;

bool Search(const vector<int> &li, int n) {
  for (auto p = li.begin(); p != li.end(); ++p) {
    if (n == *p) {
      return true;
    }
  }
  return false;
}

int main() {
  vector<int> my_vector = {1, 2, 3, 4, 5};
  cout.setf(ios_base::boolalpha);
  cout << Search(my_vector, 2) << endl;
  cout << Search(my_vector, 6) << endl;
  system("pause>nul");
  return 0;
}
