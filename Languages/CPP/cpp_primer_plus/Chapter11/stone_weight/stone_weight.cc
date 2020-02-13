#include"stone_weight.h"
#include<iostream>

namespace weight {
	
using std::cout;
using std::endl;

/* Default consturtor */
StoneWeight::StoneWeight() {
	stone_ = 0;
	pounds_ = pounds_left_ = 0.0;
}

/* Two arguments consturtor */
StoneWeight::StoneWeight(int stone, double pounds_left) {
	stone_ = stone; pounds_left_ = pounds_left;
	GetPounds();
}

/* One argument consturtor */
StoneWeight::StoneWeight(double pounds) {
	pounds_ = pounds;
	GetStones();
}

/* Quiet deconsturtor */
StoneWeight::~StoneWeight() {}

void StoneWeight::GetStones() {
	stone_ = int(pounds_) % kStonePerWeight;
	pounds_left_ =  int(pounds_) / kStonePerWeight + pounds_ - int(pounds_);  
}

void StoneWeight::GetPounds() {
	pounds_ = stone_ * kStonePerWeight + pounds_left_;
}

void StoneWeight::ShowPounds() const {
	cout << "Pounds: " << pounds_ << endl;
}

void StoneWeight::ShowStones() const {
	cout << "Stones: " << stone_
			 << "pounds: " << pounds_left_
			 << endl;
}

std::ostream& operator<<(std::ostream &os, const StoneWeight x) {
	os << "The objects weights ";
	x.ShowPounds();
	return os;
}
 
} 	// Namespace ends
