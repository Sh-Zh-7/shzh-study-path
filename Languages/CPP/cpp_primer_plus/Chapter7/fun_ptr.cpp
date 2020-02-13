#include<iostream>
#include<cstring>
using namespace std;
const int SIZE {20};

struct Info {
	int time;
	char name[SIZE];
};

Info betsy(int);
Info pam(int);
void estimate(int, Info (*)(int));

int main() {
	int line;
	cout << "How many lines of code do you need?";
	cin >> line;
	estimate(line, betsy);
	estimate(line, pam);
	return 0;
}

Info betsy(int line) { 
	Info result;
	strncpy(result.name, __func__, SIZE);
	result.time = 0.05 * line; 
	return result;
}

Info pam(int line) {
	Info result;
	strncpy(result.name, __func__, SIZE);
	result.time = 0.03 * line + 0.0004 * line * line;
	return result;
}

void estimate(int line, Info (*pf)(int)) {
	cout << "Here is " << pf(line).name << "'s estimate:\n";
	cout << line << " will take " << pf(line).time << " hours.\n";
}

