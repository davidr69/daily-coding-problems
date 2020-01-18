#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> products(const vector<int> nums) {
	//
	vector<int> newlist;
	int outer = 0;
	for_each(nums.begin(), nums.end(), [&](int i) {
		int current = 1, inner = 0;
		for_each(nums.begin(), nums.end(), [outer, &inner, &current](int j) {
			if(inner++ != outer) {
				current *= j;
			}
		});
		outer++;
		newlist.push_back(current);
	});
	return newlist;
}

void disp(const vector<int> nums) {
	cout << "[";
	for(int num: nums) {
		cout << num << " ";
	}
	cout << "]" << endl;
}

int main(int argc, char *argv[]) {
	vector<int> list = {1, 2, 3, 4, 5};
	vector<int> newlist = products(list);
	disp(newlist);
	list = {3, 2, 1};
	newlist = products(list);
	disp(newlist);
}
