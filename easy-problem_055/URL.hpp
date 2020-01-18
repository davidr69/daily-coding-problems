#include <string>
#include <unordered_map>

using namespace std;

class URL {
private:
	unordered_map<string, string> map;
	void sha256(const string, unsigned char[]);
	string get_path(string);
public:
	string shorten(string);
	string restore(string);
};
