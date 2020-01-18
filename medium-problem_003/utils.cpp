#include <vector>
#include <string>

using namespace std;

namespace utils {
	const char search[] =  "{},:";

	vector<string> tokenize(const string str) {
		vector<string> tokens;
		const char *copy = str.c_str(); // faster accessing chars in an array than a string object
		int pos, prev = 0, len = sizeof(search)/sizeof(char);
		for(pos = 0; pos < str.size(); pos++) { // position within the string
			for(int inner = 0; inner < len; inner++) { // position within punctuators
				if(copy[pos] == search[inner]) { // found a punctuator?
					if(pos == 0) { // first one
						tokens.push_back(string(1, search[inner])); // add to vector
						prev = 1;
						continue;
					} else {
						// was there a string betwee, or are the punctuators consecutive?
						if(pos == prev) {
							tokens.push_back(string(1, copy[pos]));
							prev++;
							continue;
						}
						// capture the string first
						string other = str.substr(prev, pos - prev);
						tokens.push_back(other);
						// and now the punctuator
						tokens.push_back(string(1, copy[pos]));
						prev = pos + 1;
					}
				}
			}
		}
		return tokens;
	}
}
