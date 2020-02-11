#include<iostream>
#include<list>
#include<deque>
using namespace std;

int main() {
  list<int> li = {5, 2, 4, 1, 3};
  deque<int> odd_deque, even_deque;
  for (auto i = li.cbegin(); i != li.cend(); ++i) {
    if (*i % 2 == 1) {
      odd_deque.push_back(*i);
    } else {
      even_deque.push_back(*i);
    }
  }
  cout << "The Two deques are:(first odd, second even):\n";
  for (const auto i : odd_deque) {
    cout << i << " ";
  }
  cout << endl;
  for (const auto i : even_deque) {
    cout << i << " ";
  }
  cout << endl;
  system("pause>nul");
  return 0;
}