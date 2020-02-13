#include<iostream>
#include<climits>
using namespace std;

template<typename T, int SIZE = 5> 
T max5(const T* a) {
	T max =  INT_MIN;
	for (int i = 0; i < SIZE; ++i) {
		if (a[i] > max) max = a[i];
	}
	return max;
} 

int main() {
	int int_array[5] = {4, 1, 5, 3, 2};
	double double_array[5] = {1.1, -0.5, 3.3, 4.5, 9.96};
	cout << max5(int_array) << endl;
	cout << max5(double_array) << endl;
	return 0;
}
