#include <algorithm>
#include <map>
#include "map_time.hpp"

void MapTime::set(const int key, const int val, const int time) {
	auto search = data.find(key);
	if(search == data.end()) {
		std::map<int, int> obj = {{time, val}};
		data[key] = obj;
	} else {
		data[key][time] = val;
	}
}

int *MapTime::get(const int key, const int time) {
	// since 0 is a valid return value, cannot init to 0
	int *num = nullptr;
	int val = 0;
	for_each(data[key].begin(), data[key].end(), [&](std::pair<int,int> el) {
		// first = time, second = val
		if(time >= el.first) {
			val = el.second;
			if(num == nullptr) {
				num = &val;
			}
		}
	});
	return num;
}
