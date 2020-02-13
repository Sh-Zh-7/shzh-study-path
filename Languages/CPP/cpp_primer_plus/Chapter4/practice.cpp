#include<iostream>
#include<string>

using namespace std;
const int SIZE {20};

struct info {
	char first_name[SIZE];
	string last_name;
	char grade;
	unsigned int age;	
};

int main(void) {
	info *person = new info;
	
	cout << "What's your first name:";
	cin.getline(person->first_name, SIZE);
	cout << "What's your last name:";
	cin >> person->last_name;
	cout << "What letter grade do you deserve:";
	cin >> person->grade;
	cout << "What is your age:";
	cin >> person->age;
	
	cout << "Name:"
			 << person->first_name << ','
			 << person->last_name << endl;
	cout << "Grade:" << person->grade << endl;
	cout << "Age:" << person->age << endl;
	
	delete person;
	return 0;
}
