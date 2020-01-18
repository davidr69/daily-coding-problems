all: bit_arr.o problem_137.cpp
	g++ -O3 -std=c++17 bit_arr.o problem_137.cpp -o problem_137

bit_arr.o: bit_arr.cpp
	g++ -O3 -std=c++17 -c bit_arr.cpp -o bit_arr.o

clean:
	if [ -f bit_arr.o ] ; then rm bit_arr.o; fi
	if [ -f problem_137 ] ; then rm problem_137; fi
