#include"my_complex.h"
#include<iostream>

namespace complex {
	
using std::istream;
using std::ostream;
using std::cout;
using std::endl;
	
Complex Complex::operator~() const { return Complex(x_, -y_); }

Complex Complex::operator+(const Complex& c) const { 
	return Complex(c.x_ + x_, c.y_ + y_); 
}

Complex Complex::operator-(const Complex& c) const {
	return Complex(x_ - c.x_, y_ - c.y_);
} 

double Complex::operator*(const Complex&c) const {
	return (x_ * c.x_ + y_ * c.y_);
}

Complex Complex::operator*(double n) const {
	return Complex(n * x_, n * y_);
}

/* overload '<<' so that we can use cin << to any Complex type */
istream& operator>>(istream& is, Complex& c) {
	cout << "real: "; 
	is >> c.x_;
	cout << "imaginary: "; 
	is >> c.y_;
	return is;
}

ostream& operator<<(ostream& os, const Complex& c) {
	os << "(" << c.x_ << ", " << c.y_ <<"i)";
	return os; 
}

Complex operator*(double n, const Complex& c) {
	return c * n;
}
 
} 	// Namespace ends
