#include<iostream>
using namespace std;

void repeat(int n, const string &s) {
	for (int i = 0; i < n; ++i) {
		cout << s << endl;
	}
}

void repeat(const string &s) {
	cout << s << endl;
}

int main() {
	repeat(10, "I'm OK");
	repeat("But you're kind of stupid.");
	return 0;
}
