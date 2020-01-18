#include <iostream>
#include <vector>

using namespace std;

int remove(vector<vector<char>> arr) {
	int rows = arr.size();
	if(rows == 1) {
		return 0;
	}
	int cols = arr[0].size();
	int count = 0;
	for(int col=0; col<cols; col++) {
		for(int row=0; row<rows - 1; row++) {
			if(arr[row + 1][col] < arr[row][col]) {
				count++;
				break;
			}
		}
	}
	return count;
}

int main() {
	vector<vector<char>> arr1 {{
		{'c', 'b', 'a'},
		{'d', 'a', 'f'},
		{'g', 'h', 'i'}
	}};
	cout << "Remove " << remove(arr1) << " from matrix 1" << endl;

	vector<vector<char>> arr2 {{
		{'a', 'b', 'c', 'd', 'e', 'f'}
	}};
	cout << "Remove " << remove(arr2) << " from matrix 2" << endl;

	vector<vector<char>> arr3 {{
		{'z', 'y', 'x'},
		{'w', 'v', 'u'},
		{'t', 's', 'r'}
	}};
	cout << "Remove " << remove(arr3) << " from matrix 3" << endl;

	return 0;
}
