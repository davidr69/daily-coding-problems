#include <string>

class BinTree {
private:
	BinTree *left;
	BinTree *right;
	std::string data;
public:
	static BinTree *node(std::string, BinTree *, BinTree *);
	void showTree(const int depth);
	int calculate();
};
