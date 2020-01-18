#include <iostream>
#include <vector>
#include "sllist.hpp"

using namespace std;

LinkedList merge(vector<LinkedList> lists) {
	vector<int *> listPtr;
	for(int i = 0; i<lists.size(); i++) {
		listPtr.push_back(lists[i].next());
	}

	LinkedList newlist;
	do {
		int lowestIdx, lowestVal, nulls = 0;
		bool init = true;
		for(int i = 0; i<listPtr.size(); i++) {
			if(listPtr[i] == nullptr) { // make sure to skip over nulls
				nulls++;
				continue;
			}
			if(init == true) { // first non-null value
				lowestIdx = i;
				lowestVal = *listPtr[i];
				init = false;
			}
			if(*listPtr[i] < lowestVal) {
				lowestVal = *listPtr[i];
				lowestIdx = i;
			}
		}
		if(nulls == listPtr.size()) {
			break;
		}
		newlist.append(lowestVal);
		listPtr[lowestIdx] = lists[lowestIdx].next();
	} while(true);
	return newlist;
}

int main() {
	LinkedList list1, list2, list3, list4;
	int primes[] = {2, 3, 5, 7, 11, 13, 17};
	for(int n: primes) {
		list1.append(n);
	}

	int fibonacci[] = {2, 3, 5, 8, 13, 21, 34};
	for(int n: fibonacci) {
		list2.append(n);
	}

	int squares[] = {4, 9, 16, 25, 36, 49, 64};
	for(int n: squares) {
		list3.append(n);
	}

	int random[] = {1, 6, 14, 18, 22, 27, 30};
	for(int n: random) {
		list4.append(n);
	}

	vector<LinkedList> lists = {list1, list2, list3, list4};
	LinkedList newlist = merge(lists);

	newlist.display();
	return 0;
}
