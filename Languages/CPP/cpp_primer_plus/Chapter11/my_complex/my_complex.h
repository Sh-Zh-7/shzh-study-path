#ifndef COMPLEX_H_
#define COMPLEX_H_

#include<iostream>	// Using some types from iostream header

namespace complex {

class Complex {
 public:
 	// Constuctor and destuctor functions
 	Complex();
 	Complex(double, double);
 	~Complex();
 	
 	// Friend functions
 	friend std::istream& operator>>(std::istream&, Complex&);
 	friend std::ostream& operator<<(std::ostream&, const Complex&);
 	
 	// Operators overload
 	Complex operator~() const;
 	Complex operator+(const Complex&) const;
 	Complex operator-(const Complex&) const;
 	double operator*(const Complex&) const;
 	Complex operator*(double) const;
 	
 	// Add other friend functions to overload multiply operator
 	friend Complex operator*(double, const Complex&);
 	
 private:
 	double x_, y_;
};

inline Complex::Complex() { x_ = y_ = 0.0; }

inline Complex::Complex(double a, double b) { x_ = a; y_ = b; }

inline Complex::~Complex() {}		// Quiet function

}		// Namespace ends

#endif  	// COMPLEX_H_ ends 
