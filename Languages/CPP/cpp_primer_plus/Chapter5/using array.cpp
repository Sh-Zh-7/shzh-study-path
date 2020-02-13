#include<iostream>
#include<array>
using namespace std;
const int SIZE {16};

int main() {
	array<long double, SIZE>a;
	a[0] = 1;
	for (int i = 1; i < SIZE; ++i) {
		a[i] = a[i - 1] * i;
		cout << a[i] << endl;;
	}
	return 0;
}
