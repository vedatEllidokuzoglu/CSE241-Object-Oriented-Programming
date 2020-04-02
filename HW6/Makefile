all: exe
	
exe:
	g++ -std=c++0x -c GTUSet.cpp
	g++ -std=c++0x -c GTUVector.cpp
	g++ -std=c++0x -c main.cpp

	g++ -o exe GTUSet.o GTUVector.o main.o

clean:
	rm *.o exe
