all: graph.o problem_11.cpp
	g++ -O3 -std=c++17 graph.o problem_11.cpp -o problem_11

graph.o: graph.cpp
	g++ -O3 -std=c++17 -c graph.cpp

clean:
	if [ -f problem_11 ] ; then rm problem_11; fi
	if [ -f graph.o ]; then rm graph.o; fi
