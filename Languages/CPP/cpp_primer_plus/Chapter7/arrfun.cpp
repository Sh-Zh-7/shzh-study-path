#include<iostream>
const int SIZE {5};

void fill_array(double [], int);
void revalue_array(double ,double [], int);
void show_array(const double [], int);

int main() {
	double factor;
	double *a = new double[SIZE];
	
	fill_array(a, SIZE);
	std::cout << "Enter revaluation factor:";
	std::cin >> factor;
	revalue_array(factor, a, SIZE);
	show_array(a, SIZE);
	
	delete []a;
	return 0;
} 

void fill_array(double a[], int n) {
	using namespace std;
	double temp;
	for (int i = 0; i < n; ++i) {
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin) {
			cin.clear();
			while (cin.get() != '\n') {
				continue;
			}
			cout << "Bad input, input progress terminated.\n";
			break;
		} 
		else if (temp < 0){
			break;
		}
		a[i] = temp;
	}
}

void revalue_array(double r, double a[], int n) {
	using std::cout;
	for (int i = 0; i < n; ++i) {
		a[i] *= r;
	}
}

void show_array(const double a[], int n) {
	using std::cout;
	using std::endl;
	for (int i = 0; i < n; ++i) {
		cout << "Property #" << (i + 1) << ": $";
		cout << a[i] << endl;
	}
	cout << "Done!\n";
}
