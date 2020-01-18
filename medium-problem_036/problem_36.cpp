#include <iostream>
#include <cstdlib>

using namespace std;

class Node {
private:
	int number;
	Node *left;
	Node *right;
	void showTree(int);

public:
	Node(int);
	~Node();

	void insert(int);
	void disp();
	int max2();
};

Node::Node(int num) {
	number = num;
	left = NULL;
	right = NULL;
}

Node::~Node() {
	if(this->left != NULL) {
		delete this->left;
	}
	if(this->right != NULL) {
		delete this->right;
	}
}

void Node::insert(int num) {
	Node *node = new Node(num);
	Node *curr = this;
	while(true) {
		if(num == curr->number) {
			// reject duplicates
			return;
		}
		if(num < curr->number) {
			if(curr->left == NULL) {
				curr->left = node;
				break; // found where to put it
			} else {
				curr = curr->left;
			}
		} else {
			if(curr->right == NULL) {
				curr->right = node;
				break;
			} else {
				curr = curr->right;
			}
		}
	}
}

void Node::showTree(const int depth) {
	if(this->right != NULL) {
		(this->right)->showTree(depth + 1);
	}
	cout << std::string(depth, '.') << number << endl;
	if(this->left != NULL) {
		(this->left)->showTree(depth + 1);
	}
}

int Node::max2() {
	int rv;
	Node *ptr = this;
	while(ptr->right != NULL) {
		rv = ptr->number;
		ptr = ptr->right;
	}
	return rv;
}

void Node::disp() {
	showTree(0);
}

int main(int argc, char* argv[]) {
	Node *tree = new Node(20);
	int vals[] = {8, 18, 30, 12, 2, 22, 26, 14, 6, 24, 4, 10, 16, 32, 28};
	for(int val: vals) {
		tree->insert(val);
	}
	cout << "2nd max: " << tree->max2() << endl;
	return 0;
}
