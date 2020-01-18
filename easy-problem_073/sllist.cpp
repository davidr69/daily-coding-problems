#include <iostream>
#include "sllist.hpp"

using namespace std;

LinkedList::LinkedList() {
	head = NULL;
	tail = NULL;
}

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

void LinkedList::reverse() {
	Node *ptr = head; // node A
	head = tail;
	tail = ptr;
	Node *prev = NULL;

	while(ptr != NULL) {
		Node *future = ptr->next; // node B
		ptr->next = prev;
		prev = ptr;
		ptr = future;
	}
}

void LinkedList::display() {
	Node *ptr = head;
	while(ptr != NULL) {
		cout << ptr->value << endl;
		ptr = ptr->next;
	}
}
