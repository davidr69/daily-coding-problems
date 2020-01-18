#include <iostream>
#include "bintree.cpp"

int main() {
	BinTree<char> tree;
	tree.add('d');
	tree.add('b');
	tree.add('a');
	tree.add('c');
	tree.add('f');
	tree.add('e');

	tree.disp();
	std::cout << std::endl;
	tree.invert();
	tree.disp();

	std::cout << "========================" << std::endl;
	BinTree<int> tree2;
	tree2.add(4);
	tree2.add(2);
	tree2.add(1);
	tree2.add(3);
	tree2.add(6);
	tree2.add(5);

	tree2.disp();
	std::cout << std::endl;
	tree2.invert();
	tree2.disp();
}
