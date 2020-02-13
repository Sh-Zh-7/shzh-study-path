#include<iostream>
#include<cstdlib>
#include<cstring>

template<typename T, int n>
class MyArray {
 public:
 	// Constructor functions
 	MyArray() {}
 	explicit MyArray(const T&);
 	
 	// Override operators
 	T& operator[](int);
 	T operator[](int i) const;
 	
 private:
 	T a[n];
};

template<typename T, int n>
MyArray<T, n>::MyArray(const T& v) {
	for (int i = 0; i < n; ++i) {
		a[i] = v;
	}
}

template<typename T, int n> 
T& MyArray<T, n>::operator[](int index) {
	if (index < 0 || index >= n) {
		std::cerr << "Error!\n";
		std::exit(EXIT_SUCCESS);
	}
	return a[index];
}

template<typename T, int n>
T MyArray<T, n>::operator[](int index) const {
	if (index < 0 || index >= n) {
		std::cerr << "Error!\n";
		std::exit(EXIT_SUCCESS);
	}
	return a[index];
}

int main(int argc, char *argv[]) {
	using namespace std;

	MyArray<double, 10> sum;
	MyArray<double, 10> total;
	MyArray<MyArray<double, 5>, 10> a;
	
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j) {
			a[i][j] = i * 10 + j + 1;
		}
	}
	
	for (int i = 0; i < 10; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout.width(3);
			cout << a[i][j];
		}
		cout << endl;
	}
	
	return 0;
}




