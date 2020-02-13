#include<iostream>

int main(void) {
	using namespace std;
	
	int *p_int_array = new int[10];
	for (int i = 0; i < 10; ++i) {
		p_int_array[i] = i;
	}
	for (int i = 9; i >= 0; --i) {
		cout << p_int_array[i] << ' ';
	}
	delete [] p_int_array;
	
	return 0;
} 
