#include"circule_ellipse.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

const double PI { 3.14159 };

void BaseEllipse::Move(double offset_x, double offset_y) {
	x_ += offset_x;
	y_ += offset_y;
}

void BaseEllipse::Show() const {
	cout << "x : " << x_ << endl;
	cout << "y : " << y_ << endl;
}

double Ellipse::Area() const {
	return (PI * a_ * b_);
}

void Ellipse::Show() const {
	BaseEllipse::Show();
	cout << "a : " << a_ << endl;
	cout << "b : " << b_ << endl;
}

double Circule::Area() const {
	return (PI * r_ * r_); 	
} 

void Circule::Show() const {
	BaseEllipse::Show();
	cout << "r: " << r_ << endl;
}


