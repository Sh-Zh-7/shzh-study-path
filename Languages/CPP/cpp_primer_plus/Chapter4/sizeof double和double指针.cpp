#include<iostream>

int main(void) {
	using namespace std;
	
	int y = 0;
	int *x = &y;
	 
	cout << "Size of type int: " << sizeof(int) << endl;
	cout << "Size of int pointer: " << sizeof(new int) << endl;
	cout << "And the address of integer value is:" << x << endl;
	cout << "Size of type double: " << sizeof(double) << endl;
	cout << "Size of double pointer: " << sizeof(new double) << endl;
	 
	return 0;
} 
