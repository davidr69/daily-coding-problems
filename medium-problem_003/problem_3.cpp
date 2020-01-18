#include <iostream>
#include <cassert>
#include "Node.cpp"

using namespace std;

int main() {
	Node node("root", new Node("left", new Node("left.left")), new Node("right"));
	cout << "Original: " << node.toJson() << endl;
	string marshal = node.serialize();
	cout << "Serialized as: " << marshal << endl;
	Node *orig = Node::deserialize(marshal);
	cout << "Copy: " << orig->toJson() << endl;
	assert(orig->getLeft()->getLeft()->getVal() == "left.left");
	cout << "Assertion passed" << endl;
	return 0;
}
