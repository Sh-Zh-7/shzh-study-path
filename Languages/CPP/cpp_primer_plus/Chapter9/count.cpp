#include<iostream>
#include<cstring>
using namespace std;
constexpr int MAX {20};

void count(const char *s) {
	static int total;
	unsigned int length = 0;
	while (*s++) {
		length++;
	}
	cout << "\" " << s << " \" has total " << length << " characters.\n";
	total += length;
	cout << total << " characters total.\n"; 
}

int main() {
	char str[MAX];
	char temp;
	cout << "Enter a line:\n";
	cin.get(str, MAX);
	while (cin) {
		do {
			temp = cin.get();
		} while (temp != '\n');
		count(str);
		cout << "Enter the next line(empty line to quit):\n";
		cin.get(str, MAX);
	}
	cout << "Bye!\n";
	return 0;
} 
