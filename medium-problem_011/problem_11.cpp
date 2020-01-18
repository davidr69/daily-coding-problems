#include <iostream>
#include <algorithm>
#include "graph.hpp"

using namespace std;

int main() {
	Graph g;
	g.addWord("dog");
	g.addWord("deer");
	g.addWord("deal");
	g.addWord("deep");
	g.addWord("defer");
	g.addWord("dee");
	g.display();

	vector<string *> res = g.search("de");
	cout << "Found " << res.size() << " matches" << endl;
	for_each(res.begin(), res.end(), [](string *str) {
		cout << *str << endl;
	});
	return 0;
}
