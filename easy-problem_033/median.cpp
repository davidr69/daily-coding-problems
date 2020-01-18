#include <iostream>
#include "median.hpp"

using namespace std;

void Median::addNum(int num) {
	if(nums.size() == 0) {
		nums.push_back(num);
		return;
	}

	int i = 0;
	for(; i<nums.size(); i++) {
		if(num < nums[i]) {
			break;
		}
	}

	nums.insert(nums.begin() + i, num);
}

void Median::display() {
	cout << "[" << nums[0];
	for(int i = 1; i< nums.size(); i++) {
		cout << ", " << nums[i];
	}
	cout << "]" << endl;
}

double Median::calcMedian() {
	int mid = nums.size() / 2; // rounds down properly
	if(nums.size() % 2 == 0) { // have to get average
		return (nums[mid - 1] + nums[mid]) / 2.0;
	} else {
		return nums[mid];
	}
}
