#include <vector>
#include <string>
#include <algorithm> // for "find"
#include <iostream>
#include "graph.hpp"

using namespace std;

/**
 * Examine all nodes at this level
 */
Graph *Graph::contains(char search) {
	Graph *ptr = nullptr, *temp; // temp so I don't eval twice later
	if(nodes.size() == 0) {
		return nullptr;
	}
	for(int i = 0; i<nodes.size(); i++) {
		temp = nodes.at(i);
		if(temp->c == search) {
			ptr = temp;
			break;
		}
	}
	return ptr;
}

/**
 * createNodes
 * parameter: "word" - the word that needs to be reflected in the graph
 * parameter: "offset" - index of the character currently being stored/evalluated
 * 
 * Since this is a recursive method, the *this* object will be different on
 * each invocation of the method, and it represents a sub-node in the graph.
 */
void Graph::createNodes(const string word, const int offset) {
	if(offset == word.size()) {
		endNode = true;
		return; // all characters processed
	}
	Graph *node = contains(word[offset]); // check if this character exists at this depth
	if(node == nullptr) { // not found
		node = new Graph();
		node->c = word[offset];
		nodes.push_back(node);
	}
	node->createNodes(word, offset + 1);
}

void Graph::addWord(string str) {
	createNodes(str, 0);
}

void Graph::display() {
	if(c != '\0') {
		cout << "Display ... " << c << endl;
	}
	for_each(nodes.begin(), nodes.end(), [](Graph *g) {
		g->display();
		cout << endl;
	});
}

void Graph::build(vector<string *> *results, string trail) {
	trail += c;
	if(endNode) {
		results->push_back(new string(trail));
		// not necessarily end of traversal, so fall through
	}
	if(nodes.size() == 0) { // leaf node
		if(!endNode) { // don't push twice
			results->push_back(new string(trail));
		}
	} else {
		for(int i=0; i<nodes.size(); i++) {
			string orig = trail;
			nodes[i]->build(results, trail);
			trail = orig;
		}
	}
}

vector<string *> Graph::search(string str) {
	vector<string *> *results = new vector<string *>();

	Graph *ptr = this;
	for(int pos = 0; pos < str.size(); pos++) {
		ptr = ptr->contains(str[pos]);
	}
	for(int i = 0; i<ptr->nodes.size(); i++) {
		ptr->nodes[i]->build(results, str);
	}
	return *results;
}
