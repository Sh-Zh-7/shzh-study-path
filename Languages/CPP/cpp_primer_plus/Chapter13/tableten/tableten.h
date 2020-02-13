/*
	Name: TableTennisPlayer 
	Copyright: No copyrights
	Author: Greg Shen
	Date: 11/05/19 22:44
	Description: A simple header from C Primier Plus
*/

#ifndef TABLETEN_H_
#define TABLETEN_H_

#include<iostream>
#include<string>
using std::string;
using std::cout;

/* Base class */
class TableTennisPlayer {
 public:
 	TableTennisPlayer(const string& fname = "none", const string& lname = "none",
	 									bool has = false);
 	TableTennisPlayer(const TableTennisPlayer&);
 	
 	void ShowName() const;
 	bool HasTable() const;
 	void SetTable(bool);
	 
 private:
  string fname_;
  string lname_;
  bool has_table_;
};

/* Derived class */
class RatedPlayer : public TableTennisPlayer {
	public:
	 RatedPlayer(unsigned int, const string&, const string&, bool);
	 RatedPlayer(unsigned int, const TableTennisPlayer&);
	 
	 unsigned int GetRating() const;
	 void SetRating(unsigned int rate);
	 
	private:
	 unsigned int rate_;
};

/* Inline tabletennis class's functions */
// Constructor function
inline TableTennisPlayer::TableTennisPlayer(
		const string& fname,
		const string& lname,
		bool has)
		: fname_(fname), lname_(lname), has_table_(has) {}

// Copy Constructor function		
inline TableTennisPlayer::TableTennisPlayer(const TableTennisPlayer& ttp) {
	fname_ = ttp.fname_;
	lname_ = ttp.lname_;
	has_table_ = ttp.has_table_;
}

// Show player's name
inline void TableTennisPlayer::ShowName() const { 
	cout << fname_ << ", " << lname_;
}

// Judge wether the player has a table
inline bool TableTennisPlayer::HasTable() const { return has_table_; }	
  
// Set the player's condition
inline void TableTennisPlayer::SetTable(bool has) { has_table_ = has; }


/* Inline rateplayer class's functions */
// Constructor function
inline RatedPlayer::RatedPlayer(unsigned int rate, const string& lname,
																const string& fname, bool has_table)
		: TableTennisPlayer(lname, fname, has_table), rate_(rate) {}

// Overloading constructor function
inline RatedPlayer::RatedPlayer(unsigned int rate,
															  const TableTennisPlayer& ttp)
		: TableTennisPlayer(ttp), rate_(rate) {}
		
// Set rating
inline void RatedPlayer::SetRating(unsigned int rate) { rate_ = rate; } 
	
// Get rating	
inline unsigned int RatedPlayer::GetRating() const { return rate_; }		
 			 
#endif 
