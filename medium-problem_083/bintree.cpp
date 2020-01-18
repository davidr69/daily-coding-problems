#include <iostream>
#include "bintree.hpp"

using namespace std;

template<class T>
void BinTree<T>::add(T newval) {
	Node *next = new Node(); // stage the new node
	next->val = newval;

	if(root == nullptr) {
		root = next;
		return;
	}

	Node *ptr = root;

	// don't need recursion for this
	while(true) {
		if(newval < ptr->val) {
			if(ptr->left == nullptr) {
				ptr->left = next;
				break;
			} else {
				ptr = ptr->left;
			}
		} else {
			if(ptr->right == nullptr) {
				ptr->right = next;
				break;
			} else {
				ptr = ptr->right;
			}
		}
	}
}

template<class T>
void BinTree<T>::showTree(Node *ptr, const int depth) {
	if(ptr->right != nullptr) {
		showTree(ptr->right, depth + 1);
	}
	cout << string(depth, '\t') << ptr->val << endl;
	if(ptr->left != nullptr) {
		showTree(ptr->left, depth + 1);
	}
}

template<class T>
void BinTree<T>::disp() {
	showTree(root, 0);
}

template<class T>
void BinTree<T>::flip(Node *ptr) {
	if(ptr == nullptr) {
		return;
	}
	flip(ptr->left);
	flip(ptr->right);
	Node *temp = ptr->left;
	ptr->left = ptr->right;
	ptr->right = temp;
}

template<class T>
void BinTree<T>::invert() {
	flip(root);
}
