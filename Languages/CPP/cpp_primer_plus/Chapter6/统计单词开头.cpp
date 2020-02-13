#include<iostream>
#include<cctype>
#include<string> 
using namespace std;

int main() {
	cout << "Enter words(q to quit):\n";
	string temp;
	unsigned int v_count, c_count, o_count;
	
	cin >> temp;
	v_count = c_count = o_count = 0; 
	while (temp.compare("q")) {	// Ã»Óöµ½qÊ±
	 	if (isalpha(temp[0])) {
	 		if (temp[0] == 'a' || temp[0] == 'e' || temp[0] == 'i' || temp[0] == 'o' || temp[0] == 'u') {
	 			++v_count;
			 } else {
			 	++c_count;
			 }
		 } 
		 else if (!isblank(temp[0])){
		 	++o_count;
		 }
		 cin >> temp; 
	}
	
	cout << v_count << " words beginning with vowels.\n";
	cout << c_count << " words beginning with consonants.\n";
	cout << o_count << " others.\n";
	
	return 0;
} 
