#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

map<char, char> const lookup = {
	{')','('}, {']','['}, {'}','{'}
};

bool lex(string str) {
	stack<char> s;
	for(int i = 0; i < str.length(); i++) {
		char k = (char) str[i];
		auto search = lookup.find(k);
		if(search == lookup.end()) { // not found
			s.push(k);
		} else { // pop
			if(s.size() == 0) { // nothing else to match against
				return false;
			} else {
				char v = s.top();
				s.pop();
				if(search->second == v) { // "first" is the key, "second" is the value
					continue;
				} else {
					return false;
				}
			}
		}
	}
	if(s.size() == 0) {
		return true;
	} else {
		return false;
	}
}

int main() {
	cout << lex("([])[]({})") << endl;
	cout << lex("([)]") << endl;
	cout << lex("((()") << endl;
	return 0;
}
