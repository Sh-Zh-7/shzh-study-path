#include<iostream>
using namespace std;

int main(void) {
	cout << "What year was your house built?\n";
	int year;
	(cin >> year).get();
	
	cout << "What's your address?\n"; 
	const int SIZE = 20;
	char address[SIZE];
	cin.getline(address, SIZE);
	
	cout << "Year built: " << year << endl;
	cout << "Address: " << address << endl;
	
	return 0;
}
