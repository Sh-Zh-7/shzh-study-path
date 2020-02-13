#include<iostream>
using namespace std;

int main() {
	char ch;
	
	cout << "Type, and I shall repeat:\n";
	while (cin.get(ch)) {
		if (ch == '\n') {
			cout << ch;
		} else {
			cout << ch + 1;
		}
	}
	
	return 0;
}
