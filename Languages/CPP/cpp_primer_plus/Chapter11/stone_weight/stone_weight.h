#ifndef STONE_WEIGHT_H_
#define STONE_WEIGHT_H_

#include<iostream>

namespace weight {
	
class StoneWeight{
 public:
 	// k字打头的大驼峰 
 	enum { kStonePerWeight = 14 };
 	
 	StoneWeight(); 	// Default construction
 	StoneWeight(int, double);
 	StoneWeight(double);
 	~StoneWeight();
 	
 	friend std::ostream& operator<<(std::ostream&, const StoneWeight);
 	
 	void ShowPounds() const;
 	void ShowStones() const;

 private:
 	void GetStones();
 	void GetPounds();
  
	double pounds_;
	int stone_;
	double pounds_left_;	
};

}		// Namespace ends

#endif  // STONE_WEIGHT_H_ ends
