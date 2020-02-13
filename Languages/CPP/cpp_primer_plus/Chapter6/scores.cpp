#include<iostream>
#include<vector>
const int ROUND {5};

int main() {
	using namespace std;
	
	unsigned int count = 0;
	double total = 0.0;
	vector<double>score(ROUND);
	cout << "Please enter your golf scores:\n";
	cout << "You must enter 5 rounds.\n";
	
	while (count++ < ROUND) {
		cout << "round #" << count << ": ";
		while (!(cin >> score[count - 1])) {
			cin.clear();
			while (cin.get() != '\n') {
				continue;
			}
			cout << "Please enter a number:";
		}
	}

	for (int i = 0; i < ROUND; ++i) {
		total += score[i];
	}	
	cout << (total / ROUND) << " = average score 5 rounds\n";
	
	return 0;
} 
