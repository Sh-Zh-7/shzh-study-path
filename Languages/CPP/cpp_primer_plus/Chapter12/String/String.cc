#include"String.h"
#include<iostream>
#include<cstring>
using namespace std;

namespace string {
	
/* Static data member initialization */	
int String::number_ = 0;

/* Define constructors and destructor */ 
String::String() {
	++number_;
	length_ = 0;
	str_ = nullptr;
}

String::String(const char * str) {
	++number_;
	length_ = strlen(str);
	str_ = new char[length_ + 1];
	strncpy(str_, str, String::CINLIM);
}

String::String(const String& str) {
	++number_;
	length_ = str.length_;
	str_ = new char[length_ + 1];
	strncpy(str_, str.str_, String::CINLIM);	 
}

String::~String() { 
	--number_;
	delete [] str_;
}

/* Overloading operators */
String& String::operator=(const String& str) {
	if (this == &str) {
		return *this;
	}
	delete [] str_;
	length_ = str.length_;
	str_ = new char[length_ + 1];
	strncpy(str_, str.str_, String::CINLIM);
	return *this;	
}

String& String::operator=(const char *str) {
	delete [] str_;
	length_ = strlen(str);
	str_ = new char[length_ + 1];
	strncpy(str_, str, String::CINLIM);
	return *this;
}

istream& operator>>(istream& is, String& str) {
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is) {
		str.str_ = temp;
	}
	while (is && is.get() != '\n') {}	
	return is;	
}

ostream& operator<<(ostream& os, const String& str) {
	os << str.str_;
	return os;
}

bool operator<(const String& s1, const String& s2) {
	return (strcmp(s1.str_, s2.str_) < 0);
}

bool operator>(const String& s1, const String& s2) {
	return (s2 < s1);
}

bool operator==(const String& s1, const String& s2) {
	return (strcmp(s1.str_, s2.str_) == 0);	
}
	
	
}  	// Namespace ends 
