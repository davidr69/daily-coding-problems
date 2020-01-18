#include <iostream>
#include "URL.hpp"

using namespace std;

int main() {
	URL url;
	string shorty = url.shorten("http://www.foobar.com/some_long_url_goes_here");
	cout << shorty << endl;

	shorty = url.shorten("https://www.example.com:1234/this_is_a_longer_url_than_before_for_sure");
	cout << shorty << endl;

	cout << "Restore 1: " << url.restore("B4vBcL") << endl;
	cout << "Bad restore: " << url.restore("missing") << endl;
	return 0;
}
