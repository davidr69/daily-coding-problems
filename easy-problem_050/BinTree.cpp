#include <iostream>
#include <string>
#include "BinTree.hpp"

using namespace std;

BinTree *BinTree::node(string str, BinTree *l, BinTree *r) {
	BinTree *node = new BinTree();
	node->data = str;
	node->left = l;
	node->right = r;
	return node;
}

void BinTree::showTree(const int depth) {
	if(this->right != NULL) {
		(this->right)->showTree(depth + 1);
	}
	cout << string(depth, '\t') << data << endl;
	if(this->left != NULL) {
		(this->left)->showTree(depth + 1);
	}
}

int BinTree::calculate() {
	if(data == "*") {
		return left->calculate() * right->calculate();
	} else if(data == "+") {
		return left->calculate() + right->calculate();
	} else if(data == "-") {
		return left->calculate() - right->calculate();
	} else if(data == "/") {
		return left->calculate() / right->calculate();
	} else { // the it must be numeric
		try {
			int x = stoi(data);
			return x;
		} catch(invalid_argument e) {
			cout << "Cannot convert " << data << endl;
			return 0;
		}
	}
}
