#include<iostream>
#include<valarray>

int main() {
	using namespace std;
	
	valarray<double> my_array1(10);
	cout << "Testing for \"size\" methods:\n";
	cout << my_array1.size() << endl;
	
	valarray<double> my_array2(3, 10);
	cout << "Testing for another method to initialize:\n";
	for (auto my_number : my_array2) {
		cout << my_number << " ";
	}
	cout << endl << endl;
	
	// set to #.###
	streamsize precision = cout.precision(3);
	ios_base::fmtflags format = cout.setf(ios_base::fixed, ios_base::floatfield);
	cout << "The other way to initialize:\n";
	double a[5] = {1.0, 2.0, 3.0, 4.0, 5.0};
	valarray<double> my_array3(a, 5);
	for (double my_number : my_array3) {
		cout << my_number << " ";
	}
	cout << endl;
	
	return 0;
} 
