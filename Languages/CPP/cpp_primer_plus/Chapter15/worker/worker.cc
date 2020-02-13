#include"worker.h"
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

// Worker methods

Worker::~Worker() {}

void Worker::Set() {
	cout << "Enter worker's fullname: ";
	getline(cin, fullname_);
	cout << "Enter id of the worker: ";
	cin >> id_;
	while (cin.get() != '\n') {
		continue;
	}
}

void Worker::Show() const {
	cout << "Worker's name: " << fullname_ << endl;
	cout << "Worker's id: " << id_ << endl;
}

// Waiter methods

void Waiter::Set() {
	Worker::Set();
	cout << "Enter waiter's pananche rating: ";
	cin >> panache_;
	while (cin.get() != '\n') {
		continue;
	}
}

void Waiter::Show() const {
	Worker::Show();
	cout << "Waiter's panache: " << panache_ << endl;
}

// Singer methods

const char* Singer::pv[] = {
	"Other", "alto", "contralto",
	"soprano", "bass", "baritione", "tenor"
};

void Singer::Set() {
	Worker::Set();
	cout << "Enter the range of voice: ";
	cin >> voice_;
	while (cin.get() != '\n') {
		continue;
	}
}

void Singer::Show() const {
	Worker::Show();
	cout << "Singer's voice: " << pv[voice_] << endl;
}
