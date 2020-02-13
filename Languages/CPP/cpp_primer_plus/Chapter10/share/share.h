#ifndef _SHARE_H_
#define _SHARE_H_

#include<string>

class Stock {
 public:
 	 void Acquire(const std::string&, long, double);
 	 void Buy(long, double);
 	 void Sell(long, double);
 	 void Update(double);
 	 void Show();
 	 
 	private:
	 std::string company_;
	 long shares_;
	 double share_val_;
	 double tot_val_;
	 
	 void set_tot() {
	 	 tot_val_ = shares_ * share_val_; 		
	 } 
};
 

#endif 
