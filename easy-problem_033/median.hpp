#include <vector>

class Median {
private:
	std::vector<int> nums;
public:
	void addNum(int);
	void display();
	double calcMedian();
};
