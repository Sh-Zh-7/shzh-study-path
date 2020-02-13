#include"student.h"
#include<iostream>
using namespace std;
using namespace student;

constexpr int MAX {3};

void Set(Student&, int);

int main(int argc, char *argv[]) {
	Student students[MAX] = {
		Student(MAX), Student(MAX), Student(MAX)};
	
	for (int i = 0; i < MAX; ++i) {
		Set(students[i], MAX);
	}
	
	cout << "Students' list:\n";
	for (int i = 0; i < MAX; ++i) {
		cout << students[i].Name() << endl;
	}
	
	cout << "Result:\n";
	for (int i = 0; i < MAX; ++i) {
		cout << students[i];
		cout << "Average: "
				 << students[i].Average() << endl;
	}
	
	cout << "Done!\n";
	return 0;
}

void Set(Student& stu, int n) {
	cout << "Please enter students' names:"; 
	GetLine(cin, stu);
	cout << "Please enter students' grades:";
	for (int i = 0; i < n; ++i) {
		cin >> stu[i];
	}
	while (cin.get() != '\n') {
		continue;
	}
}
