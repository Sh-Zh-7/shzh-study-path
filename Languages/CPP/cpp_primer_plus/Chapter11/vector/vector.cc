#include"vector.h"
#include<cmath>
using namespace std;

namespace myvector {

/* ������������� */ 
Vector::Vector() {
	mode_ = RECT;
	x_ = y_ = r_ = angle_ = 0;
}

Vector::Vector(double n1, double n2, Mode mode) {
// ǰ���������ȿ�����xy��Ҳ������r�ͽǶ� 
	mode_ = mode;
	if (mode == RECT) {
		x_ = n1; y_ = n2;
		set_r_angle();
	} else {
		r_ = n1; angle_ = n2;
		set_x_y();
	}
}

Vector::~Vector() {}

void Vector::Reset(double n1, double n2, Mode mode) {
	mode_ = mode;
	if (mode == RECT) {
		x_ = n1; y_ = n2;
		set_r_angle();
	} else {
		r_ = n1; angle_ = n2;
		set_x_y();
	}
}

/* ˽�к�����Ա */
void Vector::set_x_y() {
	x_ = r_ * cos(angle_);
	y_ = r_ * sin(angle_); 
}

void Vector::set_r_angle() {
	r_ = sqrt(x_ * x_ + y_ * y_);
	angle_ = atan2(y_, x_);
}

/* ���������ض��� */
Vector Vector::operator+(const Vector& v) const {
	return Vector(x_ + v.x_, y_ + v.y_);
}

Vector Vector::operator-(const Vector& v) const {
	return Vector(x_ - v.x_, y_ - v.y_);
}

Vector Vector::operator-() const {
	return Vector(-x_, -y_);
}

Vector Vector::operator*(double n) const {
	return Vector(n * x_, n * y_);	
} 

Vector operator*(double n, const Vector& v) {
	return v * n;
}

std::ostream& operator<<(ostream& os, const Vector& v) {
	if (v.mode_ == Vector::RECT) {
		os << "x: " << v.x_ << " y: " << v.y_ << endl;
	} else {
		os << "r: " << v.r_ << " angel: " << v.angle_ << endl;
	}
	return os;
}

} 	// Namespace ends
