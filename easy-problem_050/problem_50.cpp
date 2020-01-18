#include <iostream>
#include <string>
#include "BinTree.hpp"

using namespace std;

int main() {
	// construct the tree
	BinTree *left = BinTree::node("+", BinTree::node("3", NULL, NULL), BinTree::node("2", NULL, NULL));
	BinTree *right = BinTree::node("+", BinTree::node("4", NULL, NULL), BinTree::node("5", NULL, NULL));
	BinTree *root = BinTree::node("*", left, right);
	root->showTree(0);
	cout << "--------------------------" << endl;
	cout << root->calculate() << endl;
	return 0;
}
