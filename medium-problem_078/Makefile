all: sllist.o problem_78.cpp
	g++ -O3 -std=c++17 sllist.o problem_78.cpp -o problem_78

sllist.o: sllist.cpp
	g++ -O3 -std=c++17 -c sllist.cpp -o sllist.o

clean:
	if [ -f problem_78 ] ; then rm problem_78; fi
	if [ -f sllist.o ] ; then rm sllist.o; fi
