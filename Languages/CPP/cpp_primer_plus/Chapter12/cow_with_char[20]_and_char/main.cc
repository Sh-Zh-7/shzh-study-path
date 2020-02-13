#include"cow.h"
#include<iostream>

int main(int argc, char* argv[]) {
	using namespace std;
	using namespace cow;
	
	Cow my_cow1("zly", "sleep", 50);
	Cow my_cow2;
	my_cow2 = my_cow1;
	
	cout << my_cow1;
	cout << my_cow2;
	
	return 0;
}
