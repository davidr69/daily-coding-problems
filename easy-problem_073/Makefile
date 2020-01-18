all: sllist.o problem_73.cpp
	g++ -std=c++17 sllist.o problem_73.cpp -o problem_73

sllist.o: sllist.cpp
	g++ -std=c++17 -c sllist.cpp -o sllist.o

clean:
	if [ -f problem_73 ] ; then rm problem_73; fi
	if [ -f sllist.o ] ; then rm sllist.o; fi
