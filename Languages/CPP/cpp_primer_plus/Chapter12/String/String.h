#ifndef STRING_H_
#define STRING_H_

#include<iostream>
using std::istream;
using std::ostream;

namespace string {
	
class String {
public:
	enum {CINLIM = 81};
	
	// Constructors and destructors
	String();
	String(const char *);
	String(const String&);
	~String();
	
	// Friend functions
	friend istream& operator>>(istream&, String&);
	friend ostream& operator<<(ostream&, const String&);
	friend bool operator>(const String&, const String&);
	friend bool operator<(const String&, const String&);
	friend bool operator==(const String&, const String&);
		
	// Overloadded operator methods
	String& operator=(const String&);
	String& operator=(const char *);
	char& operator[](int index);
	const char& operator[](int index) const;

	// Static method
	static int HowMany();
	
	// Other method
	int Length();
	
 private:
 	static int number_;
 	
 	int length_;
 	char * str_;
}; 	

inline int String::HowMany() { return number_; }

inline int String::Length() { return length_; }

inline char& String::operator[](int index) { return str_[index]; }

inline const char& String::operator[](int index) const {
	return str_[index];
}

} 	// Namespace ends
#endif 	// STRING_H_ ends
