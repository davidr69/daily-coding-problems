#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

class Stack {
private:
	static Stack *tail;
	Stack *next;
	int value;
public:
	Stack();
	~Stack();
	void push(const int num);
	int *pop(void);
	int *max(void);
	void disp();
};

Stack *Stack::tail = NULL;

Stack::Stack() {
	//
}

Stack::~Stack() {
	//
}

void Stack::push(const int num) {
	Stack *s = new Stack();
	s->value = num;
	if(tail == NULL) {
		s->next = NULL;
		tail = s;
	} else {
		s->next = tail;
		tail = s;
	}
}

int *Stack::pop(void) {
	if(tail == NULL) {
		return NULL;
	}
	int *rv = &tail->value;
	Stack *ptr = tail->next;
	delete tail;
	tail = ptr;
	return rv;
}

int *Stack::max(void) {
	if(tail == NULL) {
		return NULL;
	}
	int *max = &(tail->value);
	Stack *ptr = tail;
	while(ptr->next != NULL) {
		ptr = ptr->next;
		if(ptr->value > *max) {
			max = &(ptr->value);
		}
	}
	return max;
}

/*
	Display in the reverse order than it's stored
*/
void Stack::disp() {
	Stack *ptr = tail;
	std::list<int> nums;
	cout << "[";
	while(ptr != NULL) {
		nums.push_front(ptr->value);
		ptr = ptr->next;
	}
	std::for_each(nums.begin(), nums.end(), [](int i){
		cout << i << " ";
	});
	cout << "]" << endl;
}

int main(int argc, char *argv[]) {
	Stack *stack = new Stack();
	cout << "Pop (non-init): " << stack->pop() << endl;
	stack->push(5);
	stack->push(3);
	stack->push(9);
	stack->push(6);
	stack->disp();
	cout << "Pop: " << *(stack->pop()) << endl;
	stack->disp();
	cout << "Max: " << *stack->max() << endl;
	return 0;
}
