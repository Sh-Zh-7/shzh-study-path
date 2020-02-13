#include<iostream>
using namespace std;

typedef int Item;

class List {
 public:
 	List();
 	
 	bool AddItem(const Item&);
 	bool IsEmpty() const;
 	bool IsFull() const;
 	void Visit(void (*pf)(Item&));
 	
 private:
 	enum {MAX = 5};
 	Item a_[MAX];
 	int size_;
};

List::List() {
	size_ = 0;
}

bool List::IsEmpty() const {
	return (size_ == 0);
}

bool List::IsFull() const {
	return (size_ == MAX);
}

bool List::AddItem(const Item &item) {
	if (this->IsFull()) {
		return false;
	} else {
		a_[++size_] = item;
		return true;
	}
}

int main() {
	List list;
	for (int i = 0; i < 6; ++i) {
		list.AddItem(i);
	}
	cout.setf(ios_base::boolalpha);
	cout << list.IsFull() << endl;
	return 0;
}
