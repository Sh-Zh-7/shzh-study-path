#include<iostream>
using namespace std;

int main() {
	cout << "Please enter one of the following choice:\n";
	cout << "c) carnivore                   p) pianist\n";
	cout << "t) tree                        g) game\n";
	
	char choice;
	cin >> choice;
	while (choice != 'c' && choice != 'p' && choice != 't' && choice != 'g') {
		while (cin.get() != '\n') {
			continue;
		}
		cout << "Please enter a, c, p, t or g:";
		cin >> choice;
	}
	cout << "A maple is a tree.\n";
	
	return 0; 	
}
