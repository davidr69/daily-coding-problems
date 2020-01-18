#include <iostream>
#include <ctime>

using namespace std;

int rand5() {
	return rand() % 5 + 1; // from 1 to 5
}

int rand7() {
	int num = rand5();
	return num + (rand5() % 3); // adds 0 to 2
}

int main() {
	srand(time(NULL)); // seed the randomizer
	for(int i = 0; i < 50; i++) {
		cout << rand7() << " ";
	}
	cout << endl;
	return 0;
}
