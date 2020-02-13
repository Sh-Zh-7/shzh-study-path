#include<iostream>
#include<string>
using namespace std;

inline const string& left(const string& s, int n = 1) { return s; }

int main() {
	string str;
	cout << "Enter a string:\n";
	getline(cin, str);
	string answer1 = left(str, 3);
	cout << answer1 << endl;
	string answer2 = left(str);
	cout << answer2 << endl;
	return 0;
} 

