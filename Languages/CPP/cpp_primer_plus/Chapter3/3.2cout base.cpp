#include<iostream>

int main(void) {
	using namespace std;
	int number_10 = 10;
	int number_8 = 010;
	int number_16 = 0x10;
	cout << "default:\n";
	cout << "Decimal:" << number_10 << endl;
	cout << "Octal:" << number_8 << endl;
	cout << "Hexadecimal:" << number_16 << endl;
	cout << "After a little bit changes\n";
	cout << oct << number_8 << endl;
	cout << hex << number_16 << endl;
}
