#include"cd.h"
#include<iostream>
#include<cstring>

namespace cd{

using std::cout;
using std::endl;
using std::strcpy;
using std::strncpy;

/* Functions of Cd's declaration */

Cd::Cd(const char* performance, const char* label,
			 int sections, double playtime)
		: sections_(sections), play_time_(playtime) {
	strncpy(performance_, performance, MAX);
	strncpy(label_, label, MAX);				
}	

Cd::Cd(const Cd& cd): sections_(cd.sections_), play_time_(cd.play_time_) {
	strcpy(performance_, cd.performance_);
	strcpy(label_, cd.label_);
}

Cd::~Cd() {} 	// Quiet destructor function

Cd& Cd::operator=(const Cd& cd) {
	if (this == &cd) {
		return *this;
	}
	strcpy(performance_, cd.performance_);
	strcpy(label_, cd.label_);
	sections_ = cd.sections_;
	play_time_ = cd.play_time_;
	return *this;
} 

void Cd::Report() const {
	cout << "Performance: " << performance_ << endl;
	cout << "Label: " << label_ << endl;
	cout << "Section: " << sections_ << endl;
	cout << "Play time: " << play_time_ << endl; 
}

/* The declaration of Classic's declaration*/
Classic::Classic(const char *s0, const char *s1, const char *s2,
				int section, double playtime)
		: Cd(s1, s2, section, playtime) {
	str_ = new char[20];
	strcpy(str_, s0);
}

Classic::Classic(const char *s0, const Cd& cd)
		: Cd(cd) {
	str_ = new char[20];
	strcpy(str_, s0);
}

Classic::~Classic() { delete [] str_; }

void Classic::Report() const {
	cout << str_ << endl;
	Cd::Report();
}

Classic& Classic::operator=(const Classic& cl) {
	if (this == &cl) {
		return *this;
	}
	delete [] str_;
	Cd::operator=(cl);
	str_ = new char[20];
	strcpy(str_, cl.str_);
} 

	
}		// Namespace cd ends


