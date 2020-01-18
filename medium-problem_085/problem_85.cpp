#include <iostream>

int calc(const int num, const int b) {
	return ((num ^ (b - 1)) | num) - (b - 1);
}

int main() {
	// return x if b = 1, y if b = 0
	int x = 12345, y = 67890;
	std::cout << "x = " << x << ", y = " << y << std::endl;
	for(int b = 0; b<2; b++) {
		std::cout << "b = " << b << " ... ";
		std::cout << calc(x, b) + calc(y, abs(b - 1)) << std::endl;
	}
	return 0;
}
