#include<iostream>
using namespace std;

template<class T1, class T2>
auto Max(const T1& x, const T2& y) -> decltype(x + y) {
	return x > y? x: y;
}

int main(void) {
	int x = 2;
	double y = 1;
	cout << Max(x, y) << endl;
	return 0;
}
