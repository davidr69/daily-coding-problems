all: URL.o problem_55.cpp
	g++ -w -std=c++17 URL.o problem_55.cpp -o problem_55 -lcrypto

URL.o: URL.cpp
	g++ -w -std=c++17 -c URL.cpp

clean:
	if [ -f problem_55 ] ; then rm problem_55; fi
	if [ -f URL.o ]; then rm URL.o; fi
