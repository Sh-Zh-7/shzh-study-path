/*
	Name: student.h
	Copyright: No copy right
	Author: Greg Shen
	Date: 18/05/19 14:33
	Description: A simple class declaration for students
*/

#ifndef _STUDENT_H_
#define _STUDENT_H_

#include<iostream>
#include<string>
#include<valarray>

namespace student {

using std::istream;
using std::ostream;
using std::string;
using std::valarray;

// A class for students
class Student {
 public:
 	typedef valarray<double> ArrayDb;
 	
 // Constructor definations
 	Student(): name_("Null Student"), grade_() {}
 	explicit Student(const string& name): name_(name), grade_() {}
	explicit Student(int size): name_("Nully"), grade_(size) {}
	Student(const string& name, int size): name_(name), grade_(size) {}
	Student(const string& name, double *arr, int size)
			: name_(name), grade_(arr, size) {} 
	Student(const string& name, const ArrayDb& arr): name_(name), grade_(arr) {}
	
 // Destructor definations
  virtual ~Student() {}
  
 // friend functions declarations
  // Input functions
  friend istream& operator>>(istream&, Student&); 	// One word
  friend istream& GetLine(istream&, Student&);		// One line
  // Output functions
  friend ostream& operator<<(ostream&, const Student&);
  
 // Other functions
  double Average() const;
  const string& Name() const;
  double& operator[](int);
  double operator[](int) const;
  
 private:
 	// Datas
 	string name_;
 	ArrayDb grade_;
 	
 	// Private functions 
 	ostream& ArrOut(ostream& os) const;	 	
};
	
}

#endif 	// _STUDENT_H_ ends 
