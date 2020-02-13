#include<iostream>

int main(void) {
	using namespace std;
	int ch;
	unsigned int count = 0;
	while ((ch = cin.get()) != EOF) {
		cout << char(ch);
		count++;
	}
	return 0;
}
