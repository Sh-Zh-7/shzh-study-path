#include<iostream>
#include<string>
using namespace std;

struct car {
	char name[20];
	unsigned int year;
};

int main() {
	int number;
	cout << "How many cars do you wish to catalog?";
	(cin >> number).get();
	car *cars = new car[number + 1];
	
	for (int i = 1; i <= number; ++i) {
		cout << "Car #" << i << ":" << endl;
		cout << "Please enter the make:";
		cin.getline(cars[i].name, 20);
		cout << "Please enter the year make:";
		(cin >> cars[i].year).get();		
	}
	
	cout << "Here is your collection:\n";
	for (int i = 1; i <= number; ++i) {
		cout << cars[i].year << " " << cars[i].name << endl;
	}
	
	delete []cars;
	return 0; 
}
