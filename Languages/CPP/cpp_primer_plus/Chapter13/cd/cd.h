#ifndef _CD_H_
#define _CD_H_

namespace cd {
	
class Cd {
 public:
 	Cd(const char * s1 = "none", const char * s2 = "none", int s = 0, double p = 0.0);
 	Cd(const Cd&);
 	virtual ~Cd();
 	
 	virtual void Report() const;
 	Cd& operator=(const Cd&);
 
 private:
 	static const int MAX = 20;
 	char performance_[MAX];
 	char label_[MAX];
 	int sections_;
	double play_time_;  	
};

class Classic: public Cd {
 public:
 	Classic(const char* = "none", const char* = "none",
	 				const char* = "none", int = 0, double = 0.0);
 	Classic(const char*, const Cd&);
 	virtual ~Classic();
 	
 	virtual void Report() const;
 	Classic& operator=(const Classic&);
 	
 private:
 	char *str_;
};
	
}		// Namespace cd ends

#endif 	// _CD_H_ ends 
