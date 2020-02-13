#include"circule_ellipse.h"
#include<iostream>
using namespace std;

int main(int argc, char *argv[]) {
	Ellipse my_ellipse(0, 0, 2, 2);
	Circule my_circule(0, 0, 10);
	my_ellipse.Show();
	cout << my_ellipse.Area() << endl; 
	return 0;
}
