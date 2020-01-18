#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(const vector<int> prices) {
	if(prices.size() == 0) {
		return 0;
	}
	int max = 0;
/*	for(int outer = 0; outer < prices.size(); outer++) {
		for(int inner = outer + 1; inner < prices.size(); inner++) {
			if(prices[inner] - prices[outer] > max) {
				max = prices[inner] - prices[outer];
			}
		}
	}*/
	int offset = 1;
	for_each(prices.begin(), prices.end(), [prices, &max, &offset](int outer) {
		for_each(prices.begin() + offset++, prices.end(), [outer, &max](int inner) {
			if(inner - outer > max) {
				max = inner - outer;
			}
		});
	});
	return max;
}

int main(int argc, char **argv) {
	vector<int> nums = {9, 11, 8, 5, 7, 10};
	cout << "Max: " << solution(nums) << endl;
	return 0;
}
