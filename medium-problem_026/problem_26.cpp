#include <iostream>

using namespace std;

template<class T>
class SLL {
private:
	struct SLL *next;
	T val;
	int count = 0;
public:
	SLL(T);
	void add(T);
	void deleteAt(int);
	void disp();
};

template<class T>
SLL<T>::SLL(T item) {
	val = item;
	next = NULL;
}

template<class T>
void SLL<T>::add(T item) {
	SLL *ptr = this;
	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next = new SLL(item);
	count++;
}

template<class T>
void SLL<T>::disp() {
	cout << count << " items" << endl;
	SLL *ptr = this;
	int idx = 1;
	while(ptr->next != NULL) {
		cout << idx++ << " = " << ptr->val << endl;
		ptr = ptr->next;
	}
}

template<class T>
void SLL<T>::deleteAt(int idx) {
	// idx is guaranteed to be less than the size of the list, according to the description
	SLL *ptr = this;
	for(int i = 0; i < count - idx - 1; i++) {
		ptr = ptr->next;
	}
	SLL *skip = ptr->next->next;
	delete ptr->next;
	ptr->next = skip;
	count--;
}

int main() {
	SLL<int> root(42);
	srand(time(NULL));
	for(int i = 0; i < 15; i++) {
		root.add(rand() % 1000);
	}
	root.disp();
	cout << "Delete 5th from end ..." << endl;
	root.deleteAt(5);
	root.disp();
	return 0;
}
