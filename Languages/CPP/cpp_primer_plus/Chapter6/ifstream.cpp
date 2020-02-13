#include<iostream>
#include<fstream>
#include<string>
using namespace std;

struct File {
	string name;
	unsigned int count = 0;
};

int main() {
	File *file = new File;
	file->count = 0;
	
	cout << "Please enter your file name:\n";
	cin >> file->name;
	
	ifstream fin;
	fin.open(file->name);
	if (!fin.is_open()) {
		cout << "Can't open " << file->name << endl;
		cout << "Program terminate.\n";
		exit(EXIT_FAILURE);
	}
	
	
	char ch;
	while (fin >> ch) {
		file->count++;
	}
	cout << "Your file include " << file->count << " words.\n";
	 
	fin.close();
	delete file;
	return 0;
}
