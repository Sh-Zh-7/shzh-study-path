#include<iostream>
#include<string>
using namespace std;

int main() {
	string temp;
	unsigned int count = 0;
	
	cout << "Enter words (to stop, type the word done):\n";
	cin >> temp;
	while (temp.compare("done")) {
		count++;
		cin >> temp;
	} 
	cout << "You entered a total of " << count << " words" << endl;
	
	return 0;
}
