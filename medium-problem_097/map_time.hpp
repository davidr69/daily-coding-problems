#include <map>

class MapTime {
private:
	std::map<int, std::map<int, int>> data;
public:
	void set(int, int, int); // key, time, value
	int *get(int, int); // key, time; must allow for nullptr return
};
