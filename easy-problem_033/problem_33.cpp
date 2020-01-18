#include <iostream>
#include "median.hpp"

int main() {
	Median stream;
	int nums[] = {2, 1, 5, 7, 2, 0, 5};
	int len = sizeof(nums)/sizeof(int);
	for(int i = 0; i<len; i++) {
		stream.addNum(nums[i]);
		std::cout << stream.calcMedian() << "\t";
		stream.display();
	}
	return 0;
}
