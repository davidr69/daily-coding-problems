#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	vector<int> nums = {-9, -2, 0, 2, 3};
	vector<int> squares;
	for_each(nums.begin(), nums.end(), [&squares](int num) {
		squares.push_back(num * num);
	});
	sort(squares.begin(), squares.end(), less<int>());

	cout << "[" << squares[0];
	for_each(squares.begin() + 1, squares.end(), [](int square) {
		cout << ", " << square;
	});
	cout << "]" << endl;
	return 0;
}
