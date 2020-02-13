#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct Info {
	string name;
	unsigned int year;
	unsigned long long price;
};

int main() {
	Info *person = new Info;
	
	cout << "Enter the make and model of automobile:";
	getline(cin, person->name);
	cout << "Enter the model year:";
	cin >> person->year;
	cout << "Enter the original asking price:";
	cin >> person->price; 
	
	ofstream fout;
	fout.open("test.txt");
	fout << "Make and model: " << person->name << endl;
	fout << "Year: " << person->year << endl;
	fout << "Was asking " << person->price << endl;
		
	delete person;
	fout.close();
	return 0;
}
