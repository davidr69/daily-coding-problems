#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "Node.hpp"
#include "utils.cpp"

using namespace std;

Node::Node() { }

Node::Node(string v, Node *l = NULL, Node *r = NULL) {
	val = v;
	left = l;
	right = r;
}

string Node::toJson() {
	stringstream ss;
	ss << "{\"val\":\"" << val << "\",\"left\":";
	if(left == NULL) {
		ss << "null";
	} else {
		ss << left->toJson();
	}
	ss << ",\"right\":";
	if(right == NULL) {
		ss << "null";
	} else {
		ss << right->toJson();
	}
	ss << "}";
	return ss.str();
}

string Node::serialize() {
	stringstream ss;
	ss << "{val:" << val ;
	if(left != NULL) {
		ss << ",left:" << left->serialize();
	}
	if(right != NULL) {
		ss << ",right:" << right->serialize();
	}
	ss << "}";
	return ss.str();
}

/*
	Recursing should allow the offset to be modified since we will have to "resume"
	when the next call ended.
*/
Node *Node::build(vector<string> str, int *offset) {
	// sample string: {val:root,left:{val:left,left:{val:left.left}},right:{val:right}}
	if(str[*offset] != "{") {
		return NULL; // malformed
	}
	(*offset)++;
	Node *node = new Node();
	while(*offset < str.size()) {
		if(str[*offset] == "val" && str[*(offset) + 1] == ":") {
			node->val = str[*(offset) + 2];
			*(offset) += 3; // skip over ":" and the value
			continue;
		}
		if(str[*offset] == "left" && str[*(offset) + 1] == ":" && str[*(offset) + 2] == "{") {
			*(offset) += 2;
			node->left = build(str, offset);
			continue;
		}
		if(str[*offset] == "right" && str[*(offset) + 1] == ":" && str[*(offset) + 2] == "{") {
			*(offset) += 2;
			node->right = build(str, offset);
			*(offset)++;
			continue;
		}
		if(str[*offset] == "}") {
			(*offset)++;
			return node;
		}
		(*offset)++;
	}
	return node;
}

Node *Node::deserialize(string src) {
	/*
		Using the following sample string, we can make some observations
		(the string is assumed to be well-formed):

			{val:root,left:{val:left,left:{val:left.left}},right:{val:right}}

		- Every "segment" will begin and end with a left curly brace.
		- Every segment will contain a "val" object
		- "left" and "right" may not be present since null values do not appear
	*/
	//
	vector<string> tokens = utils::tokenize(src);
	#ifdef DEBUG
	for_each(tokens.begin(), tokens.end(), [](string item) {
		cout << "token: " << item << endl;
	});
	#endif
	int begin = 0;
	return build(tokens, &begin);
}

Node *Node::getLeft() { return left; }

Node *Node::getRight() { return right; }

string Node::getVal() { return val; }
