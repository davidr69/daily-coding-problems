#include <iostream>

class Single {
private:
	Single();
	static int instances;
	static bool odd;
	static Single *one, *two;
public:
	static Single *getInstance();
};

Single::Single() { }

int Single::instances = 0;
bool Single::odd = true;
Single *Single::one = nullptr;
Single *Single::two = nullptr;

Single *Single::getInstance() {
	if(instances < 2) {
		Single *foo = new Single();
		if(++instances == 1) {
			one = foo;
		} else {
			two = foo;
		}
		return foo;
	} else {
		odd = !odd;
		if(odd) { // this will be backwards because we updated the status first
			return two;
		} else {
			return one;
		}
	}
}

int main() {
	Single *ptr;
	for(int i = 0 ; i < 7; i++) {
		ptr = Single::getInstance();
		std::cout << "addr: " << ptr << std::endl;
	}
	return 0;
}
