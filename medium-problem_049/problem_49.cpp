#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>

using namespace std;

mutex num_lock;
int maxsum = 0;

struct arr_args {
	vector<int> *arr;
	int *offset; // where do we begin searching?
};

void subarray(const arr_args *args) {
	int total = 0;
	int loopsum = 0;
	for_each(args->arr->begin() + *(args->offset), args->arr->end(), [&](int i) {
		loopsum += i;
		if(loopsum > total) {
			total = loopsum;
		}
	});
	lock_guard<mutex> lock(num_lock);
	{
		if(total > maxsum) {
			maxsum = total;
		}
	}
}

int main(int argc, char **argv) {
	vector<int> nums = {34, -50, 42, 14, -5, 86};
	vector<thread *> thread_arr;
	for(int i = 0; i < nums.size(); i++) {
		// not using fancy iterator because I actually want the index only
		arr_args *args = new arr_args();
		args->arr = &nums;
		args->offset = new int(i);
		thread *t = new thread(subarray, args);
		thread_arr.push_back(t);
	}
	for_each(thread_arr.begin(), thread_arr.end(), [](thread *t) {
		t->join();
	});
	cout << "Max is: " << maxsum << endl;
	return 0;
}
