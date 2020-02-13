/*
	Name: worker_mi
	Copyright: No copyright
	Author: Greg Shen
	Date: 23/05/19 14:00
	Description: ...
*/

#include"worker_mi.h"
#include<iostream>

namespace worker {

using std::cin;
using std::cout;
using std::endl;

// Worker methods
Worker::~Worker() {}

void Worker::Data() const {
	cout << "Name: " << fullname_ << endl;
	cout << "ID: " << id_ << endl;
}

void Worker::Get() {
	cout << "Enter worker's name:";
	getline(cin, fullname_);
	cout << "Enter worker's id:";
	cin >> id_;
	while (cin.get() != '\n') {
		continue;
	}
}

// Waiter methods
void Waiter::Data() const {
	cout << "Panache: " << panache_ << endl; 
}

void Waiter::Get() {
	cout << "Enter waiter's panache rating:";
	cin >> panache_;
	while (cin.get() != '\n') {
		continue;
	}
}

void Waiter::Show() const {
	Worker::Data();
	Data();
}

void Waiter::Set() {
	Worker::Get();
  Get();
}

// Singer methods
const char* Singer::kPv[Singer::kNumOfTypes] = {
		"other", "alto", "contralto", "soprano",
		"bass", "baritone", "tenor"
};
 
void Singer::Data() const {
	cout << "Level of voice: " << kPv[voice_] << endl;
}

void Singer::Get() {
	cout << "Enter the number for singer's vocal\
 range:\n";
 int i;
 for (i = 0; i < kNumOfTypes; ++i) {
 	 cout << i << ": " << kPv[i] << " ";
 	 if (i % 4 == 3) {
 		 cout << endl;
	 }
 }
 cout << endl;
 cin >> voice_;
 while (cin.get() != '\n') {
   continue;
 }
}

void Singer::Set() {
	Worker::Get();
	Get();
}

void Singer::Show() const {
	Worker::Data();
	Data();
}

// Singer and Waiter method
void SingerWaiter::Data() const {
	Waiter::Data();
	Singer::Data();
}

void SingerWaiter::Get() {
	Waiter::Get();
	Singer::Get();
}

void SingerWaiter::Show() const {
	Worker::Data();
	Data();
}

void SingerWaiter::Set() {
	Worker::Get();
	Get();
}

} // Namespace worker ends
