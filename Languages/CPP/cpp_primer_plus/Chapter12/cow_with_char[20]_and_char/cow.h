#ifndef _COW_H_
#define _COW_H_

#include<iostream>

namespace cow {

class Cow {
 public:
 	Cow();
 	Cow(const char *name, const char *hobby, double weight);
	Cow(const Cow& cow);
	~Cow();
	
	Cow& operator=(const Cow&);
	
	friend std::ostream& operator<<(std::ostream&, const Cow&);
	
 private:
 	static const int kLimit = 20;
 	char name_[kLimit];
 	char *hobby_;
 	double weight_;
};
	
}		// Namespace cow ends

#endif 	// _COW_H_ ends 
