#include <vector>
#include <string>

using namespace std;

class Graph {
private:
	char c = '\0';
	bool endNode = false;
	vector<Graph *> nodes;
	void createNodes(const string, int); // source string, offset
	Graph *contains(char);
	void build(vector<string *> *, string); // vector with built words, crumbs of trail for that depth
public:
	void addWord(string);
	void display();
	vector<string *> search(string);
};
