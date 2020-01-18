#include <iostream>
#include "bit_arr.hpp"

int main() {
	BitArr arr;
	arr.init(30);
	arr.set(13, 1);
	arr.display();
	std::cout << "13 = " << arr.get(13) << std::endl;
	arr.set(14, 0);
	arr.display();
	std::cout << "14 = " << arr.get(14) << std::endl;

	arr.set(13, 0);
	arr.display();
	std::cout << "13 = " << arr.get(13) << std::endl;
	arr.set(14, 1);
	arr.display();
	std::cout << "14 = " << arr.get(14) << std::endl;
	return 0;
}
