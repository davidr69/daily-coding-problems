#include <iostream>
#include <cstring>

using namespace std;

#define LEN 4

const char words[][LEN] = {
	{'F', 'A', 'C', 'I'},
	{'O', 'B', 'Q', 'P'},
	{'A', 'N', 'O', 'B'},
	{'M', 'A', 'S', 'S'}
};

bool find_word(const char word[]) {
	// horizontal search
	for(int row = 0; row < LEN; row++) {
		if(strncmp(word, words[row], LEN) == 0) {
			return true;
		}
	}
	 // vertical search
	 for(int col = 0; col < LEN; col++) {
		bool found = true;
		for(int row = 0; row < LEN; row++) {
			if(word[row] != words[row][col]) {
				found = false;
				break;
			}
		}
		if(found) { // this iteration matched
			return true;
		}
	}
	return false;
}

int main() {
	bool found = find_word("FOAM");
	cout << "Found 'FOAM'? " << found << endl;
	found = find_word("MASS");
	cout << "Found 'MASS'? " << found << endl;
	found = find_word("GEEK");
	cout << "Found 'GEEK'? " << found << endl;
	return 0;
}
