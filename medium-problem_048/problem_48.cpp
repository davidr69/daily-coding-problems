#include <iostream>
#include <cmath>

using namespace std;

struct Node {
	Node() { } // default constructor
	Node(char val) {
		left = NULL;
		right = NULL;
		value = val;
	}
	Node *left;
	Node *right;
	char value;
};

Node *inorder(const char arr[], const int begin, const int end) {
	if(end == begin) {
		Node *node = new Node(arr[begin]);
		return node;
	}
	int root = (end + begin) / 2;

	Node *node = new Node();
	node->value = arr[root];
	node->left = inorder(arr, begin, root - 1);
	node->right = inorder(arr, root + 1, end);
	return node;
}

/*
	Paramaters:
		arr = the actual array
		limit = the length of the array; don't need to recalculate this each time
		depth = current depth within the treep
		height = limit on how deep we should go

	This requires a depth-first approach
*/
Node *preorder(const char arr[], const int limit, const int depth, const int height) {
	static int offset = 0; // don't have to pass this around
	if(offset >= limit || depth > height) {
		return NULL;
	}
	Node *node = new Node();
	node->left = preorder(arr, limit, depth + 1, height);
	node->value = arr[offset++];
	node->right = preorder(arr, limit, depth + 1, height);
	return node;
}

void showTree(Node *node, int depth) {
	if(node->right != NULL) {
		showTree(node->right, depth + 1);
	}
	cout << std::string(depth, '\t') << node->value << endl;
	if(node->left != NULL) {
		showTree(node->left, depth + 1);
	}
}

int main(int argc, char **argv) {
	char arr[] = {'d', 'b', 'e', 'a', 'f', 'c', 'g'};
	int len = sizeof(arr) / sizeof(char);
	Node *node = inorder(arr, 0, len - 1);
	showTree(node, 0);
	cout << "-----------------" << endl;

	char arr2[] = {'a', 'b', 'd', 'e', 'c', 'f', 'g'};
	len = sizeof(arr2) / sizeof(char);
	int height = log2(len + 1); // max height of tree
	node = preorder(arr, len, 1, height);
	showTree(node, 0);
	return 0;
}
