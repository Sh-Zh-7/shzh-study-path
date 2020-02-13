#include<iostream>

class Time {
 public:
 	Time();
 	Time(int hour, int minute);
 	
 	void AddMin(int minute);
 	void AddHou(int hour);
 	void Show() const;
 	Time& operator+(const Time &time);
 	
 private:
 	int hour_;
 	int minute_;
}; 

Time::Time() {
	hour_ = minute_ = 0;
}

Time::Time(int hour, int minute) {
	hour_ = hour; minute_ = minute;
}

void Time::AddMin(int minute) {
	minute_ += minute;
	hour_ += minute_ / 60;
	minute_ %= 10;
}

void Time::AddHou(int hour) {
	hour_ += hour;
}

void Time::Show() const {
	using std::cout;
	using std::endl;
	cout << "Hour: " << hour_ << " "<< "Minute: " << minute_ << endl; 
}

Time& Time::operator+(const Time& time) {
	minute_ += time.minute_;
	hour_ += time.hour_ + minute_ / 60;
	minute_ %= 60;
	return *this;
}

int main() {
	using namespace std;
	Time plan;
	Time coding(2, 40), fixing(5, 55);
	cout << "coding + fixing:";
	(coding + fixing).Show();
	Time more_fixing(3, 28);
	cout << "total: ";
	(coding + more_fixing).Show();
	return 0;
}

