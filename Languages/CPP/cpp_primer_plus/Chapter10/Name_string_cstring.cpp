#include<iostream>
#include<cstring>
#include<string>
using namespace std;

class Name{
 public:
 	Name();
 	Name(const string&, const char* = "\0");
 	
 	void Show() const;
 
 private:
 	enum {SIZE = 10};
 	string f_name_;
 	char l_name_[SIZE];
}; 

inline Name::Name() {
	f_name_ = "";
	l_name_[0] = '\0';
}

inline Name::Name(const string &f_name, const char l_name[]) {
	f_name_ = f_name;
	strncpy(l_name_, l_name, SIZE);
}

inline void Name::Show() const {
	cout << "Name : " << l_name_ << " " << f_name_ << endl;
} 


int main() {
	Name names[3] = {
		{},
		{"Szh"},
		{"Szh", "Zly"}
	};
	for (int i = 0; i < 3; ++i) {
		names[i].Show();
	}	
	return 0;
}
