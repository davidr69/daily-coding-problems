#include <string>
#include <unordered_map>

#include <sstream>
#include <string>
#include <iomanip>
#include <openssl/sha.h>

#include "URL.hpp"

const char lookup[] = {
	'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
	'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',
	'0','1','2','3','4','5','6','7','8','9'
};

void URL::sha256(const string str, unsigned char hash[]) {
	SHA256_CTX sha256;
	SHA256_Init(&sha256);
	SHA256_Update(&sha256, str.c_str(), str.size());
	SHA256_Final(hash, &sha256);
}

string URL::get_path(string url) {
	int pos = url.find("/", url.find("//") + 2);
	return url.substr(pos + 1);
}

string URL::shorten(string str) {
	unsigned char hash[SHA256_DIGEST_LENGTH];
	sha256(get_path(str).c_str(), hash);
	ulong bits = (hash[0] << 40) + (hash[1] << 32) + (hash[2] << 24) + (hash[3] << 16) + (hash[4] << 8) + hash[5];
	int shr = 34;
	stringstream ss;
	for(int shr = 34, idx = 0; idx < 6; idx++, shr -= 6) {
		int byte = (bits >> shr) & 0x3f;
		ss << lookup[byte % sizeof(lookup)];
	}
//	ss << hex << setw(2) << setfill('0') << (int)hash[i];
	string key = ss.str();
	map[key] = str;
	return key;
}

string URL::restore(string key) {
	return map[key];
}
