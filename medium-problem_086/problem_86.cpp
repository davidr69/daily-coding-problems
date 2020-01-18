#include <iostream>
#include <stack>

using namespace std;

int remain(string str) {
	stack<char> myStack;
	for(int i=0; i<str.size(); i++) {
		char c = str[i];
		switch(c) {
			case '(':
				myStack.push(c);
				break;
			case ')':
				if(myStack.size() == 0) { // prevent segmentation fault
					myStack.push(c); // mismatch; going to push and it will not get popped
					continue;
				}
				if(myStack.top() == '(') {
					myStack.pop();
				}
				break;
		}
	}
	return myStack.size();
}

int main() {
	cout << "Remain: " << remain("()())()") << endl;
	cout << "Remain: " << remain(")(") << endl;
	return 0;
}
