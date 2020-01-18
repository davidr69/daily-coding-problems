#include <string>
#include <iostream>
#include "unistd.h"
#include "fcntl.h"

using namespace std;

string readN(const int fd, int num) {
	char buff[num + 1] = {'\0'};
	int bytesRead = read(fd, buff, num);
	string rv = string(buff);
	return rv;
}

int main() {
	int fd = open("testfile.txt", O_RDONLY);
	for(int i=0; i<3; i++) {
		string str = readN(fd, 7);
		cout << str << endl;
	}
	close(fd);
	return 0;
}
