#include <iostream>

using namespace std;

bool oneMove(const int nums[], const int len) {
	bool dipped = false; // did it already decrease?
	for(int i=0; i<len - 1; i++) {
		if(nums[i] > nums[i + 1]) {
			if(dipped) { // already dipped before
				return false;
			}
			dipped = true;
		}
	}
	return true;
}

int main() {
	int nums[] = {10, 5, 7};
	bool ok = oneMove(nums, 3);
	cout << "Compliant? " << (ok ? "yes" : "no") << endl;
	int nums2[] = {10, 5, 1};
	ok = oneMove(nums2, 3);
	cout << "Compliant? " << (ok ? "yes" : "no") << endl;
	return 0;
}
