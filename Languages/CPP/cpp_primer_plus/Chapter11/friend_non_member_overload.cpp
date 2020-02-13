#include<iostream>

class Clock {
 public:
 	Clock(int hour, int minute);
 	
 	friend std::ostream& operator<<(std::ostream&, const Clock&);
 	
 private:
 	int hour_;
 	int minute_;
};

std::ostream& operator<<(std::ostream& os, const Clock& clock) {
	using std::cout;
	using std::endl;
	os << "Hour: " << clock.hour_ << " Minute: " << clock.minute_ << endl;
	return os;
}

inline Clock::Clock(int hour, int minute) {
	hour_ = hour;
	minute_ = minute;
}

int main() {
	Clock my_clock(12, 12);
	std::cout << my_clock;
	return 0;
}
