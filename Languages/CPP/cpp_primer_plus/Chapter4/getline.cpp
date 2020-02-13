#include<iostream>

int main(void) {
	using namespace std;
	
	const int SIZE = 20;
	char name[SIZE];
	char dessert[SIZE];
	cout << "Enter your name:\n";
	cin.getline(name, SIZE);
	cout << "Enter your dessert:\n";
	cin.getline(dessert, SIZE);
	cout << "I have some delicious " << dessert
			 << " for you, " << name << endl;
	
	return 0; 
} 
