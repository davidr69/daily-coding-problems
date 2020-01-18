#include <iostream>
#include <ctime>

using namespace std;

const double mult = 4.0 / 6.0; // only calculate once

int rand7() {
	return rand() % 7 + 1; // from 1 to 7
}

int rand5(int num) {
	double new_num = (num - 1) * mult;
	return int(new_num + 1);
}

int main() {
	srand(time(NULL)); // seed the randomizer
	for(int i = 0; i < 20; i++) {
		int num = rand7();
		cout << "Orig: " << num << "; new: " << rand5(num) << endl;
	}
	return 0;
}
