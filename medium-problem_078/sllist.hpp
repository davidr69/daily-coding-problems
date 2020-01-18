class LinkedList {
private:
	struct Node {
		int value;
		Node *next;
	};
	Node *head = nullptr;
	Node *tail = nullptr; // makes appending easy
	Node *iter = nullptr; // keeps track of "next"
public:
	void append(int);
	void display();
	int *next(); // Why a pointer? Because no value can represent end-of-list; nullptr will be used for that
};
