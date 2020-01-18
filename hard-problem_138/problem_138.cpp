#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

const int currency[] = {25, 10, 5, 1};

map<int,int> change(const int change) {
	map<int,int> coins;
	int total = 0; // running total
	int pos = 0; // position within currency arr
	int current_coin; // instead of writing "currency[pos]" 3 times
	do {
		current_coin = currency[pos];
		if(total + current_coin > change) {
			// enough of the current coin
			pos++;
			continue; // can jump back to the start of the loop
		}
		total += current_coin;
		if(coins.count(current_coin) == 0) {
			coins[current_coin] = 1;
		} else {
			coins[current_coin] = coins[current_coin] + 1;
		}
	} while(total < change); // will catch when equal
	return coins;
}

string format_change(const map<int,int> nums) {
	stringstream ss;
	int num = 0;
	ss << "{";
	if(nums.size() > 0) {
		for(auto it = nums.begin(); it != nums.end(); ++it) {
			if(num > 0) {
				ss << ", ";
			}
			ss << it->first << ":" << it->second;
			num += it->second;
		}
	}
	ss << "} = " << num << " coins";
	return ss.str();
}

int main() {
	map<int,int> coins = change(16);
	cout << "16 -> " << format_change(coins) << endl;
	coins = change(23);
	cout << "23 -> " << format_change(coins) << endl;
	coins = change(9);
	cout << "9 -> " << format_change(coins) << endl;
	return 0;
}
