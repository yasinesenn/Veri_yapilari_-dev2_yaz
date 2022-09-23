all: build run

build:
	g++ -I ./include/ -o ./lib/Arraylist.o -c ./src/Arraylist.cpp
	g++ -I ./include/ -o ./lib/Radix.o -c ./src/Radix.cpp
	g++ -I ./include/ -o ./lib/readAndSort.o -c ./src/readAndSort.cpp
	g++ -I ./include/ -o ./lib/Node.o -c ./src/Node.cpp
	g++ -I ./include/ -o ./lib/AvlTree.o -c ./src/AvlTree.cpp
	g++ -I ./include/ -o ./bin/test ./lib/Arraylist.o ./lib/Radix.o ./lib/readAndSort.o ./lib/Node.o ./lib/AvlTree.o ./src/test.cpp

run: 
	./bin/test
