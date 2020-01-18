#include <iostream>
#include "RotateArr.hpp"

using namespace std;

RotateArr::RotateArr(const int *nums, int len) {
	arrSize = len;
	arr = nums;
}

int RotateArr::locator(const int search, const int begin, const int end) {
	int mid = (end + begin + 1) / 2; // +1 so that "end" becomes a candidate
	if(arr[mid] == search) { // found it!
		return mid;
	}
	if(mid == begin) { // not found
		return -1;
	}

	if(search < arr[begin]) {
		if(mid == end) { // edge case
			return -1;
		}
		if(search <= arr[mid]) {
			if(arr[begin] < arr[mid]) { // left side does not contain rotation point
				// it's on the right side
				return locator(search, mid + 1, end);
			} else {
				// it's on the left side
				return locator(search, begin, mid - 1);
			}
		} else {
			//definitely on the right
			return locator(search, mid + 1, end);
		}
	} else {
		// it's on the left side
		return locator(search, begin, mid - 1);
	}
	return -1;
}

int RotateArr::indexOf(int search) {
	return locator(search, 0, arrSize - 1);
}
