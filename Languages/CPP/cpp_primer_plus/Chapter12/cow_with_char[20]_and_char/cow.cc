#include"cow.h"
#include<cstring>
#include<iostream>

namespace cow {

using std::endl;
using std::strlen;
using std::strcpy;
using std::strncpy;
using std::ostream;

Cow::Cow(): weight_(0) {
	name_[0] = '\0';
	hobby_ = nullptr;
}

Cow::Cow(const char *name, const char *hobby, double weight) : weight_(weight) {
 	int size_of_hobby = strlen(hobby);
	
	hobby_ = new char[size_of_hobby + 1];	  
 	strncpy(name_, name, kLimit);
 	strcpy(hobby_, hobby);
}

Cow::Cow(const Cow &cow) {
	int size_of_hobby = strlen(cow.hobby_);
		
	delete [] hobby_;
	hobby_ = new char[size_of_hobby + 1];
		
	strcpy(name_, cow.name_);
	strcpy(hobby_, cow.hobby_);
}

Cow::~Cow() {
	delete [] hobby_;
}

Cow& Cow::operator=(const Cow& cow) {
	if (this == &cow) {
		return *this;
	}
	delete [] hobby_;
	hobby_ = cow.hobby_;
	strcpy(name_, cow.name_);
	weight_ = cow.weight_;
	return *this;
}

ostream& operator<<(ostream& os, const Cow& cow) {
	os << "Name: " << cow.name_ << endl
		 << "Hobby: " << cow.hobby_ << endl
		 << "Weight: " << cow.weight_ << endl;
	return os;
}

} 
