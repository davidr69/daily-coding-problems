#include <iostream>
#include <vector>
#include "Subset.cpp"

using namespace std;

int main() {
	Subset s1({15, 5, 20, 10, 35, 15, 10});
	int mid = s1.midpoint();
	cout << "mid: " << mid << endl;
	s1.split_set();
//	split_set(nums, mid);

	Subset s2({15, 5, 20, 10, 35});
	mid = s2.midpoint();
	cout << "mid: " << mid << endl;
	return 0;
}
