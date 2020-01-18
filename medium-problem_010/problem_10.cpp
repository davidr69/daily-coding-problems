#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>

using namespace std;

mutex lock, cout_lock;
int threads = 0;

// prevents output from seperate threads stomping on each other
#define trace(x) { \
	scoped_lock<mutex> lock(cout_lock); \
	cout << x << endl; \
}

// you can only pass one argument to a thread, and I need to pass 2
struct info {
	void (*fnPtr)();
	int msDelay;
};

void function1() {
	trace("Function one!");
	lock_guard<mutex> lock(mutex);
	{
		threads--;
	}
}

void function2() {
	trace("Function two!");
	lock_guard<mutex> lock(mutex);
	{
		threads--;
	}
}

void async(void *paramsPtr) {
	struct info *params = (info *) paramsPtr;
	trace("thread " << this_thread::get_id() << " sleeping for " << params->msDelay << "ms");
	this_thread::sleep_for (chrono::milliseconds(params->msDelay));
	trace("Timer done for thread " << this_thread::get_id());
	(params->fnPtr)();
}

void scheduler(void (*fn)(), int ms) {
	info *params = new info();
	params->fnPtr = fn;
	params->msDelay = ms;
	lock_guard<mutex> lock(mutex);
	{
		threads++;
	}
	thread *t = new thread(async, params);
	t->detach();
	trace("thread spawned");
}

int main() {
	scheduler(function1, 5000);
	scheduler(function2, 2000);
	bool done = false;
	while(!done) {
		trace("Waiting ...");
		this_thread::sleep_for (chrono::seconds(1));
		lock_guard<mutex> lock(mutex);
		{
			if(threads == 0) {
				done = true;
			}
		}
	}
}
