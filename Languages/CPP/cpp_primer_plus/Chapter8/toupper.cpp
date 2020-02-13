#include<iostream>
#include<string>
using namespace std;

void Toupper(string &s) {
	for (char ch : s) {
		bool is_low = (ch >= 97) && (ch <= 123);
		if (is_low) {
			cout << char(ch - 32);
		} else {
			cout << char(ch);
		}
	}
	cout << endl;
}

int main() {
	string str;
	cout << "Enter a string(q to quit):";
	getline(cin, str);
	while (str.compare("q")) {
		Toupper(str);
		cout << "Next string(q to quit):"; 
		getline(cin, str);
	}
	cout << "Bye!\n";
	return 0;
}
