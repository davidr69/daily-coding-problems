all: median.o problem_33.cpp
	g++ -O3 -std=c++17 median.o problem_33.cpp -o problem_33

median.o: median.cpp
	g++ -O3 -std=c++17 -c median.cpp -o median.o

clean:
	if [ -f problem_33 ] ; then rm problem_33; fi
	if [ -f median.o ]; then rm median.o; fi
