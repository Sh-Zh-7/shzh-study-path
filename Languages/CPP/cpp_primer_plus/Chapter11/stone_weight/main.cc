#include"stone_weight.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
using weight::StoneWeight;

int main() {
	StoneWeight x = 275;
	StoneWeight y(285.4);
	StoneWeight z(21, 8);

	cout.setf(std::ios_base::fixed, std::ios_base::floatfield);

	cout << x;
	cout << y;
	cout << z;

	x = 666;
	cout << x;

	cin.get();
	return 0;
}
