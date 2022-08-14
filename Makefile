all: Tomb

Tomb: test.o
	g++ A4-tests.o -o Tomb

test.o: A4-tests.cpp
	g++ -c A4-tests.cpp -Wall -ansi -pedantic -std=c++11

clean:
	rm -rf *o Tomb
