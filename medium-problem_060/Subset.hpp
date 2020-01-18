#include <vector>

class Subset {
private:
	std::vector<int> subset1, subset2;
	std::vector<int> nums;
	int target, running_total; // obviates the need to pass as param
	void recurse(const int);
public:
	Subset(std::vector<int>);
	int midpoint();
	void split_set();
	void disp(const std::vector<int>);
};
