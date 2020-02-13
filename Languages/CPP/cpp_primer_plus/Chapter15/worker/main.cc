#include"worker.h"
#include<iostream>
using namespace std;

constexpr int kSize {4};

int main(int argc, char* argv[]) {
	Waiter bob("Bob Apple", 314L, 5);
	Singer bec("Beverly Hills", 522L, 3);
	Waiter w_temp;
	Singer s_temp;
	Worker* workers[kSize] = {&bob, &bec, &w_temp, &s_temp};
	
	for (int i = 2; i < kSize; ++i) {
		workers[i]->Set();
	}
	
	for (int i = 0; i < kSize; ++i) {
		workers[i]->Show();
	}
	
	cout << "Done!\n";
	return 0;
}
