#include <iostream>
#include <vector>
#include <algorithm>
#include "Subset.hpp"

using namespace std;

Subset::Subset(vector<int> superset) {
	nums = superset;
}

int Subset::midpoint() {
	int total = 0;
	for_each(nums.begin(), nums.end(), [&total](int num) {
		total += num;
	});
	if(total % 2 == 0) {
		target = total / 2;
		return target;
	} else {
		return -1;
	}
}

void Subset::recurse(const int offset) {
	for(int idx = offset; idx < nums.size(); idx++) {
		//
	}
}

void Subset::split_set() {
	subset1 = nums;
	sort(subset1.begin(), subset1.end(), greater<int>());
	disp(subset1);
	running_total = 0;
	recurse(0);
}

void Subset::disp(const vector<int> nums) {
	cout << "[";
	if(nums.size() > 0) {
		cout << nums[0];
		for_each(nums.begin() + 1, nums.end(), [](int num) {
			cout << ", " << num;
		});
	}
	cout << "]" << endl;
}
