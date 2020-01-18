#include <iostream>
#include <vector>

using namespace std;

class Node {
private:
	string val;
	Node *left;
	Node *right;
	static Node *build(vector<string>, int *);
	Node(); // need this for deserialization, but don't want it public
public:
	Node(string, Node *, Node *);
	string toJson();
	string serialize();
	static Node *deserialize(string);
	Node *getLeft();
	Node *getRight();
	string getVal();
};
