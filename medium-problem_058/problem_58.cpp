#include <iostream>
#include "RotateArr.cpp"

using namespace std;

#define LEN 6

int main() {
	int arrs[LEN][LEN] = {
		{2, 8, 10, 13, 18, 25},
		{8, 10, 13, 18, 25, 2},
		{10, 13, 18, 25, 2, 8},
		{13, 18, 25, 2, 8, 10},
		{18, 25, 2, 8, 10, 13},
		{25, 2, 8, 10, 13, 18}
	};

	// all should succeed
	for(int i = 0; i < LEN; i++) {
		RotateArr rarr(arrs[i], LEN);
		int pos = rarr.indexOf(8);
		if(pos == -1) {
			cout << "Not found" << endl;
		} else {
			cout << "Pos " << pos << endl;
		}
	}
	cout << endl << endl;

	// all should fail
	for(int i = 0; i < LEN; i++) {
		RotateArr rarr(arrs[i], LEN);
		int pos = rarr.indexOf(7);
		if(pos == -1) {
			cout << "Not found" << endl;
		} else {
			cout << "Pos " << pos << endl;
		}
	}
	return 0;
}
