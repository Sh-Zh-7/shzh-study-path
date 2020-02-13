#include<iostream>

int main(void) {
	using namespace std;
	
	const int SIZE = 20;
	char name[SIZE];
	char dessert[SIZE];
	
	cout << "Enter your name:\n";
	cin.get(name, SIZE).get();
	cout << "Enter your dessert:\n";
	cin.get(dessert, SIZE).get();
	cout << "I have some delicious " << dessert
			 << " for you, " << name << ".\n";
	
	return 0;
}
