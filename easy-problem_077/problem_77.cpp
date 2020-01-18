#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct range {
	int min, max;
};

void merge(const range src, range *dest) {
	if(src.min < dest->min) {
		dest->min = src.min;
	}
	if(src.max > dest->max) {
		dest->max = src.max;
	}
}

// since we have to "return" the optimized intervals, we simply can't print, so ...
vector<range> optimize(vector<range> ranges) {
	vector<range> rv;
	rv.push_back(ranges[0]);
	for_each(ranges.begin() + 1, ranges.end(), [&rv](range r) {
		// cannot iterate dest since we might modify it
		// set 1 is "r", set 2 is "rv"
		bool merged = false;
		for(int i=0; i<rv.size(); i++) {
			if((r.min < rv[i].min && rv[i].min < r.max) || // first test: n < x < m
					(rv[i].min < r.min && r.max < rv[i].min)) { // second test: x < n < y
				merge(r, &(rv[i]));
				merged = true;
				break;
			}
		}
		if(!merged) {
			rv.push_back(r);
		}
	});
	return rv;
}

int main() {
	vector<range> intervals = {range{1,3}, range{5,8}, range{4,10}, range{20,25}};
	vector<range> optimized = optimize(intervals);
	for_each(optimized.begin(), optimized.end(), [](range r) {
		cout << "range: (" << r.min << ", " << r.max << ")" << endl;
	});
	return 0;
}
