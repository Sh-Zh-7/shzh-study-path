#include<iostream>
using namespace std;

typedef unsigned long Item;

class Stack {
 public:
 	Stack();
 	
 	bool IsFull() const;
 	bool IsEmpty() const;
 	const Item& Pop();
 	bool Push(const Item&);
 	
 private:
 	enum {MAX = 50};
 	Item items_[MAX];
 	int top_;
};

Stack::Stack() {
	top_ = 0;
}

inline bool Stack::IsFull() const {
	return (top_ == MAX);
}

inline bool Stack::IsEmpty() const {
	return (top_ == 0);
}

const Item& Stack::Pop() {
		if (!this->IsEmpty()) {
			return items_[top_--];
		}
}

bool Stack::Push(const Item &item) {
	if (!this->IsFull()) {
	 	items_[++top_] = item; 
		return true;  
	} 
	return false;
}

int main() {
	Stack stack;
	stack.Push(5);
	cout << stack.Pop() << endl;
	cout.setf(ios_base::boolalpha);
	cout << stack.IsEmpty() << endl;
	cout << stack.IsFull() << endl;
	return 0;
}



