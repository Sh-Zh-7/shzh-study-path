#include"tableten.h"
#include<iostream>

int main() {
	using std::cout;
	using std::endl;
	TableTennisPlayer player1("Tara", "Boomdea", false);
	RatedPlayer rplayer1(1140, "Mallory", "Duck", true);
	rplayer1.ShowName();
	if (rplayer1.HasTable()) {
		cout << ": has a table.\n";
	} else {
		cout << ": hasn't a table.\n";
	}
	
	player1.ShowName();
	if (player1.HasTable()) {
		cout << ": has a table.\n";
	} else {
		cout << ": hasn't a table.\n";
	}
	
	cout << "Name: ";
	rplayer1.ShowName();
	cout << "; Rating: " << rplayer1.GetRating() << endl;
	
	RatedPlayer rplayer2(1212, player1);
	cout << "Name: ";
	rplayer2.ShowName();
	cout << "; Rating: " << rplayer2.GetRating() << endl;
	
	return 0;
}
