#include"String.cc"
#include<iostream>

constexpr int SIZE {10};
constexpr int MAX {81};

int main(int argc, char* argv[]) {
	using namespace string;
	using std::cin;
	using std::cout;
	using std::endl;

	/* Greeting */
	String name;
	cout << "Hi, what's your name?\n";
	cin >> name;
	cout << name << ", please enter up to " << SIZE << " short saying\
<empty line to quit>:\n";
	
	/* Inputs */
	String sayings[SIZE];
	int total;
	char temp[MAX];
	for (int i = 0; i < SIZE; ++i) {
		cout << i + 1 <<" : " ;
		cin.get(temp, MAX);
		while (cin && cin.get() != '\n') {}		// Deal with reduntant characters
		
		if (!cin || temp[0] == '\0') {		// Empty line to quit
			total = i;
			break;
		}	else {
			sayings[i] = temp;
		} 
	} 
	
	/* Calculates */
	cout << "Here are your sayings:\n";
	for (int i = 0; i < total; ++i) {
		cout << sayings[i][0] << ": " << sayings[i] << endl;
	} 
	
  int shortest = 0;
	int first = 0;
	for (int i = 1; i < total; ++i) {
		if (sayings[first] > sayings[i]) {
			first = i;
		}
		if (sayings[shortest].Length() > sayings[i].Length()) {
			shortest = i;
		}
	}
	
	/* Outputs */
	cout << "Shortest saying:\n" << sayings[shortest] << endl;
	cout << "First alphabetically:\n" << sayings[first] << endl;
	cout << "The program used " << String::HowMany() << endl;
	
	return 0;
}
