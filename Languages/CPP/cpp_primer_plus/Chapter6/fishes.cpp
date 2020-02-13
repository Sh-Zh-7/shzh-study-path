#include<iostream>
#include<array>
using namespace std;
const int MAX {5};

int main() {
	int count = 0;
	double total = 0.;
	array<double, MAX>fishes;
	
	cout << "Please enter the weights of your fish.\n"
			 << "You may enter up to 5 fish <q to terminate>.\n";
	cout << "fish #1:";
	while (cin >> fishes[count] && ++count < MAX) {
		cout << "fish #" << count + 1 << ":";
		total += fishes[count - 1];
	}
	
	if (count == 0) {
		cout << "No fish\n";
	} else {
		cout << (total / count) << " = average weight of "
				 << count << " fish.\n";
	}
	
	cout << "done.\n";
	return 0;
}
