/*
	Name: main.cc 
	Copyright: NO copyright 
	Author: Greg Shen
	Date: 23/05/19 14:02
	Description: A test for worker_mi.h
*/

#include"worker_mi.h"
#include<iostream>
#include<cstring>

constexpr int kSize {5};

int main(int argc, char* argv[]) {
	using namespace std;
	using namespace worker;
	
	Worker* lolas[kSize];
	
  int total;
  char choice;
	for (int i = 0; i < kSize; ++i) {
		cout << "Enter the employee category:\n"
				 << "w: waiter  s: singer  "
				 << "t: singing waiter q: quit\n";
		cin >> choice;
		while (strchr("wstq", choice) == NULL) {
			cout << "Please input w or s or t or q !!\n";
			cin >> choice;
		}
		if (choice == 'q') {
			total = i;
			break;
		}
		switch(choice) {
			case 'w': lolas[i] = new Waiter;
							  break;
			case 's': lolas[i] = new Singer; 
								break;
			case 't': lolas[i] = new SingerWaiter; 
								break; 
		}
		cin.get();
		lolas[i]->Set();
	}
	
	cout << "Here is your staff:\n";
	for (int i = 0; i < total; ++i) {
		cout << endl;
		lolas[i]->Show();
	}
	
	for (int i = 0; i < total; ++i) {
		delete lolas[i];
	} 
	cout << "Done!\n";
	return 0;
}
