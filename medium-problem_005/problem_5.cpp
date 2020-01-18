#include <iostream>

using namespace std;

int nesta(int a, int b) { return a; }

int nestb(int a, int b) { return b; }

auto cons(int a, int b) {
	auto pair = [a, b](auto *f) -> int { return f(a, b); };
	return pair;
}

int main(int argc, char *argv[]) {
	auto foo = cons(3, 4);

	int (*fn1)(int, int) = nesta; // "car" method
	cout << foo(fn1) << endl;

	int (*fn2)(int, int) = nestb; // "cdr" method
	cout << foo(fn2) << endl;
	return 0;
}
