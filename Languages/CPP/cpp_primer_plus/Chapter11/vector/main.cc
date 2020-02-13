#include"vector.h"
#include<iostream>
#include<random>
#include<cmath>

constexpr double PI {acos(0) * 2};

int main() {
	using namespace std;
	using myvector::Vector;
	
	default_random_engine my_engine;
	uniform_real_distribution<double> my_random(0, 2 * PI);
	int target;
	int step_length;
	double direction;
	int steps = 0;
	Vector step;
	Vector result(0, 0);
	
	cout << "Enter target distance('q' to quit:)";
	while (cin >> target) {
		cout << "Enter step length:";
		if (!(cin >> step_length)) {
			break;
		}
		
		while (result.GetR() < target) {
			double direction = my_random(my_engine);
			step.Reset(step_length, direction, Vector::POL);
			result = result + step;
			++steps;
		}
		
		cout << "After " << steps << ", we have reached " << result;
		result.SetPol();
		cout << "\nSame as " << result << endl;
		cout << "Enter target distance('q' to quit:)";
	}
	
	return 0;
}



