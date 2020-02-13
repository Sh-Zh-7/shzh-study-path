#include<iostream>
#include<string>
using namespace std;
const int MAX {5};

void fill_string_array(string [], int);
void show_string_array(string [], int);

int main() {
	string *str_p = new string[MAX];
	cout << "Enter your 5 favorite astronomical sights:\n";
	fill_string_array(str_p, MAX);
	cout << "Your list:\n";
	show_string_array(str_p, MAX);
	delete [] str_p;
	return 0;
}

void fill_string_array(string a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << (i + 1) << ": ";
		getline(cin, a[i]);
	}	
}

void show_string_array(string a[], int n) {
	for (int i = 0; i < n; ++i) {
		cout << (i + 1) << ": " << a[i] << endl;
	}
}
