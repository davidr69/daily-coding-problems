#include <iostream>
#include "bit_arr.hpp"

void BitArr::init(int size) {
	bits = size;
	len = (size + 7) >> 3;
	data = new unsigned char[len];
	for(int i=0; i<len; i++) {
		data[i] = (char) 0;
	}
}

void BitArr::set(const int pos, const int val) {
	int skip = pos / 8; // number of bytes to skip
	if(pos >= bits) {
		return; // out of bounds
	}
	int offset = 7 - pos % 8; // offset within byte, in reverse
	unsigned char setter = 1 << offset;
	if(val == 0) {
		setter = (unsigned char) 0xff - setter;
		data[skip] &= setter;
	} else {
		data[skip] |= setter;
	}
}

void BitArr::display() {
	for(int i =0; i<len; i++) {
		unsigned char mask = 0x80;
		for(int bit=0; bit<8; bit++) {
			std::cout << ((data[i] & mask) == 0 ? "0" : "1");
			mask >>= 1;
		}
		std::cout << " ";
	}
	std::cout << std::endl;
}

int BitArr::get(const int pos) {
	// reusing this portion
	int skip = pos / 8;
	if(pos >= bits) {
		return 0;
	}
	int offset = 7 - pos % 8;
	unsigned char getter = 1 << offset;
	// end reuse
	unsigned char eval = data[skip] & getter;
	return eval == 0 ? (int) 0 : (int) 1;
}
