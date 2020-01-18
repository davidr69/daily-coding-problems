all: map_time.o problem_97.cpp
	g++ -O3 -std=c++17 map_time.o problem_97.cpp -o problem_97

map_time.o: map_time.cpp
	g++ -O3 -std=c++17 -c map_time.cpp -o map_time.o

clean:
	if [ -f map_time.o ] ; then rm map_time.o; fi
	if [ -f problem_97 ] ; then rm problem_97; fi
