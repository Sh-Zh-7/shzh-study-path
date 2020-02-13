#include<iostream>
#include"share.h"

int main() {
	using namespace std;
	Stock test;
	test.Acquire("NanoSmart",20, 12.5);
	test.Show();
	test.Buy(15, 18.125);
	test.Show();
	test.Sell(400, 20.0);
	test.Show();
	test.Buy(300000, 40.125);
	test.Show();
	test.Sell(300000, 0.125);
	test.Show(); 
	cin.get(); 
	return 0;
}
