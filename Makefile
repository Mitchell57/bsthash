CXX = g++
CXXFLAGS = -Wall -g

main: main.o HashTable.o BST.o
	$(CXX) $(CXXFLAGS) -o main main.o HashTable.o BST.o

main.o: main.cpp HashTable.h HashEntry.h BST.h utility.h
	$(CXX) $(CXXFLAGS) -c main.cpp

HashTable.o: HashTable.h HashEntry.h

clean:
	rm -rf *.o main

BSTTest.o: BSTTest.cpp BST.h utility.h
	$(CXX) $(CXXFLAGS) -c BSTTest.cpp

BST.o: BST.h
