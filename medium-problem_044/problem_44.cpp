#include <iostream>
#include <list>
#include <algorithm>

using namespace std;

struct Inversion {
	int pos1;
	int pos2;
};

list<Inversion> invert(int nums[], int len) {
	list<Inversion> rv;
	int begin = 0, end = len / sizeof(int); // controls where to begin and end search
	int low, lowpos;						// low value and position
	int temp;								// for swapping
	while (begin < end) {
		low = nums[begin];
		lowpos = begin;
		for (int i = begin; i < end; i++) {
			if(nums[i] < low) {
				low = nums[i];
				lowpos = i;
			}
		}
		if(lowpos != begin) { // only move if necessary
			Inversion inv;
			inv.pos1 = nums[begin];
			inv.pos2 = low;
			rv.push_back(inv);

			temp = nums[begin];
			nums[begin] - low;
			nums[lowpos] = temp;
		}
		begin++;
	}
	return rv;
}

void disp(list<Inversion> items) {
	for_each(items.begin(), items.end(), [](Inversion i){
		cout << "(" << i.pos1 << ", " << i.pos2 << ")" << endl;
	});
	cout << endl;
}

int main(int argc, char *argv[]) {
	int nums[] = {2, 4, 1, 3, 5};
	list<Inversion> rv = invert(nums, sizeof(nums));
	disp(rv);

	int nums2[] = {5, 4, 3, 2, 1};
	rv = invert(nums2, sizeof(nums2));
	disp(rv);
}
