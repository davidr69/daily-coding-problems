#include <iostream>
#include "sllist.hpp"

using namespace std;

void LinkedList::append(int num) {
	Node *ptr = new Node();
	ptr->value = num;
	ptr->next = NULL;

	if(head == NULL) {
		head = ptr;
	} else {
		tail->next = ptr;
	}
	tail = ptr;
}

int *LinkedList::next() {
	if(iter == NULL) {
		iter = head;
	} else {
		iter = iter->next;
	}
	return &(iter->value);
}

void LinkedList::display() {
	Node *ptr = head;
	while(ptr != NULL) {
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
}
