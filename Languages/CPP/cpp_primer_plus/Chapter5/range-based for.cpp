#include<iostream>
#include<vector>

int main() {
	using std::cout;
	using std::endl;
	std::vector<int>a{1, 3, 5, 7, 9};
	for (int x: a) {
		cout << x << '\t';
	}
	cout << endl;
	return 0;
} 
