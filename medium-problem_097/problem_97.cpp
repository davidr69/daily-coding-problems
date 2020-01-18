#include <iostream>
#include <string>
#include <sstream>
#include "map_time.hpp"

std::string eval(const int *num) {
	if(num == nullptr) {
		return "null";
	} else {
		int foo = *num; // not sure why I need to do this; get bogus number without it
		std::stringstream ss;
		ss << foo;
		return ss.str();
	}
}

int main() {
	MapTime mt1;
	mt1.set(1, 1, 0);
	mt1.set(1, 2, 2);
	std::cout << "get(1,1): " << eval(mt1.get(1, 1)) << std::endl;
	std::cout << "get(1,3): " << eval(mt1.get(1, 3)) << std::endl;

	MapTime mt2;
	mt2.set(1, 1, 5);
	std::cout << "get(1,0): " << eval(mt2.get(1, 0)) << std::endl;
	std::cout << "get(1,10): " << eval(mt2.get(1, 10)) << std::endl;

	MapTime mt3;
	mt3.set(1, 1, 0);
	mt3.set(1, 2, 0);
	std::cout << "get(1,0): " << eval(mt3.get(1, 0)) << std::endl;

	return 0;
}
