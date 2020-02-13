#include<iostream>

int main(void) {
	using namespace std;
	const int SIZE = 10;
	int a[SIZE];
	for (int i = 0; i < SIZE; ++i) {
		cout << a[i] << ' ';
	} 
	cout << endl;
	int b[SIZE] = {0};
	for (int i = 0; i < SIZE; ++i) {
		cout << b[i] << ' ';
	}
	return 0;
}
