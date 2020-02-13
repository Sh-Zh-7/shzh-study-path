#include"student.h"

namespace student {
	
using std::endl;	
	
double Student::Average() const {
	int size = grade_.size();
	if (size > 0) {
		return (grade_.sum() / size);
	} else {
		return 0;
	}
}

const string& Student::Name() const { return name_; }

double& Student::operator[](int index) { return grade_[index]; }

double Student::operator[](int index) const { return grade_[index]; }

// Every line outputs 5 numbers
ostream& Student::ArrOut(ostream& os) const {
  int size = grade_.size();
  for (int i = 0; i < size; ++i) {
  	os << grade_[i] << " ";
  	if (i % 5 == 4) {
  		os << endl;
		}
	}
	return os;
}

istream& operator>>(istream& is, Student& stu) {
	is >> stu.name_;
	return is;
}

istream& GetLine(istream& is, Student& stu) {
	getline(is, stu.name_);
	return is;
}

ostream& operator<<(ostream& os, const Student& stu) {
	os << "Name: " << stu.name_ << endl; 
	stu.ArrOut(os);
	return os;
}

}		// Namespace student ends
