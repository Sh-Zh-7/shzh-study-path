#include"share.h"
#include<iostream>

void Stock::Acquire(const std::string &company, long shares, double share_val) {
	company_ = company;
	shares_ = shares;
	share_val_ = share_val;
	set_tot();
}

void Stock::Buy(long shares, double price) {
	if (shares < 0) {
		std::cout << "Number of purchase cannot be negative!\n"
							<< "Transaction terminated!\n";
 	} else {
 		shares_ += shares;
 		share_val_ = price;
 		set_tot();
	 }
}

void Stock::Sell(long shares, double price) {
	using std::cout;
	if (shares < 0) {
		cout << "Number of shares cannot be negative!\n"
				 << "Transaction terminated!\n";
	} else if (shares > shares_) {
		cout << "You cannot sell more than you have!\n"
	 			 << "Transaction terminated!\n";
	} else {
		shares_ -= shares;
		share_val_ = price;
		set_tot();
	}
} 

void Stock::Update(double price) {
	share_val_ = price;
	set_tot();
}

void Stock::Show() {
	using std::cout;
	using std::endl;
	cout << "Company:" << company_ << endl
						<< "  Shares:" << shares_ 
						<< "  Share price:" << share_val_
						<< "  Total Worth:" << tot_val_ << endl;
}
