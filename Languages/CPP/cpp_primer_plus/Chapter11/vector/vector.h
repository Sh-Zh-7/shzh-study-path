/*
	Name: Vector
	Copyright: 
	Author: Szh
	Date: 09/05/19 20:10
	Description: A simple header
*/

#ifndef VECTOR_H_
#define VECTOR_H_

#include<iostream>

namespace myvector {
	
class Vector {
 public:
 	enum Mode {RECT, POL};
 	
 	Vector();
 	Vector(double, double, Mode mode = RECT); 
 	~Vector();
 	
 	// Operator overloading
 	Vector operator+(const Vector&) const;
 	Vector operator-(const Vector&) const;
 	Vector operator-() const;
 	Vector operator*(double n) const;
 	
 	// Friends
 	friend Vector operator*(double n, const Vector&);
 	friend std::ostream& operator<<(std::ostream&, const Vector&);
 	
 	// Some other necessary functions
 	void Reset(double, double, Mode);
 	
 	// Inline functions
 	void SetRect() { mode_ = RECT; }
 	void SetPol() { mode_ = POL; }
	double GetX() const { return x_; }
 	double GetY() const { return y_; }
 	double GetR() const { return r_; }
 	double GetAngle() const { return angle_; }
 	
 private:
	void set_x_y();
	void set_r_angle();
 	
 	Mode mode_;
 	double x_, y_;
 	double r_, angle_;	// »¡¶ÈÖÆ 
};

}	// Namespace ends

#endif	// VECTOR_H_ ends
