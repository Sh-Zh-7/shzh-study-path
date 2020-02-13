#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

template<typename T> 
const T maxn(T *a, int n) {
	T max = INT_MIN;
	for (int i = 0; i < n; ++i) {
		if (a[i] > max) max = a[i];
	}
	return max;
}

template<>
const char* maxn(char *a[], int n) {
	int *len_arr = new int[n];
	int max = INT_MIN;
	int max_index = 0;
	for (int i = 0; i < n; ++i) {
		len_arr[i] = strlen(a[i]);
		if (max < len_arr[i]) {
			max_index = i;
			max = len_arr[i];
		}
	}
	char *temp = a[max_index];
	return temp;	
}

int main() {
	const int SIZE {5};
	int a[SIZE] = {4 , 1, 3, 5, 2};
	char *ch_arr[SIZE] = {
		"Hello World!",
		"Fuck you! little man!",
		"Hello World",
		"Deep dark fantasy",
		"I'm iron man."
	};
	cout << maxn(a, SIZE) << endl;
	cout << (int *)maxn(ch_arr, SIZE) << endl;
	return 0; 
}
