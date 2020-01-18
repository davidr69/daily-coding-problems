class LinkedList {
private:
	struct Node {
		int value;
		Node *next;
	};
	Node *head;
	Node *tail; // makes appending easy
public:
	LinkedList();
	void append(int);
	void reverse();
	void display();
};
