#include <iostream>
#include <vector>
#include <algorithm> // for "sort"

using namespace std;

void recurse(const std::vector<int> nums, const int total, std::vector<int> *newlist, int *accum, int offset) {
	if(offset > nums.size()) {
		return;
	}
	if(*accum + nums[offset] <= total) {
		newlist->push_back(nums[offset]);
		*accum += nums[offset];
	}
	recurse(nums, total, newlist, accum, offset + 1);
}

vector<int> *find_sum(vector<int> src, const int total) {
	int begin = 0;
	for(int num: src) {
		if(num < total) {
			break;
		}
		begin++;
	}
	int accum = 0;
	vector<int> *newlist = new vector<int>();
	recurse(src, total, newlist, &accum, begin);
	return newlist;
}

int main(int argc, char *argv[]) {
	int arr[] = {12, 1, 61, 5, 9, 2};
	vector<int> nums (arr, arr + sizeof(arr) / sizeof(int));
	int k = 24;
	sort(nums.begin(), nums.end(), std::greater<int>());
	vector<int> *items = find_sum(nums, k);
	for(int num: *items) {
		cout << num << " ";
	}
	cout << endl;
}
