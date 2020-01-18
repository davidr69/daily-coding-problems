#ifndef __BINTREE_CPP__
#define __BINTREE_CPP__

template<class T>
class BinTree {
private:
	struct Node {
		Node *left = nullptr;
		Node *right = nullptr;
		T val;
	};
	Node *root = nullptr;
	void showTree(Node *, const int); // ptr, depth
	void flip(Node *);
public:
	void add(T);
	void disp();
	void invert();
};

#endif
