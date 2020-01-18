#include <iostream>
#include "sllist.hpp"

int main() {
	LinkedList llist;
	llist.append(1);
	llist.append(3);
	llist.append(5);
	llist.append(7);
	llist.display();
	std::cout << "--------" << std::endl;
	llist.reverse();
	llist.display();
	std::cout << "--------" << std::endl;
	// let's prove that "tail" is correct by adding more
	llist.append(9);
	llist.display();
	return 0;
}
