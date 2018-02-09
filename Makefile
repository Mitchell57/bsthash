CXX = g++
CXXFLAGS = -Wall -g

main: main.o HashTable.o
	$(CXX) $(CXXFLAGS) -o main main.o HashTable.o

main.o: main.cpp HashTable.h HashEntry.h
	$(CXX) $(CXXFLAGS) -c main.cpp

HashTable.o: HashTable.h HashEntry.h

clean:
	rm -rf *.o main
