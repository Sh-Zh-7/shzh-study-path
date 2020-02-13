#include<iostream>
using namespace std;

struct inflatable {
	char name[20];
	int id;
}; 

int main(void) {
	inflatable *person = new inflatable;
	
	cout << "Enter your name:\n";
	cin.get(person->name, 20);
	cout << "Enter your id:\n";
	cin >> person->id;
	cout << "Your name:" << person->name << endl;
	cout << "Your id:" << person->id << endl;
	
	return 0;
}
