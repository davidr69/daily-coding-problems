#include <iostream>
#include <cmath>

using namespace std;

void occurrences(const int n, const int x) {
	int count = 0;
	double factor;
	for(int i = 1; i <= sqrt(x); i++) {
		// get factors
		factor = (double) x / i; // one of them needs to be typecast to avoid automatic rounding
		if(factor == (int) factor) { // no decimal; legit factor
			if(factor <= n) { // filter out factors that do not appear on the board
				count++;
			}
		}
	}
	cout << "n = " << n << ", x = " << x << "; occurrences: " << count * 2 << endl;
}

int main() {
	occurrences(6, 12);
	occurrences(5, 16);
	occurrences(12, 24);
}
