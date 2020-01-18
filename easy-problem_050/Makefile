all: BinTree.o problem_50.cpp
	g++ -std=c++17 BinTree.o problem_50.cpp -o problem_50

BinTree.o: BinTree.cpp
	g++ -std=c++17 -c BinTree.cpp -o BinTree.o

clean:
	if [ -f BinTree.o ] ; then rm BinTree.o; fi
	if [ -f problem_50 ] ; then rm problem_50; fi
