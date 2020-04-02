all: exe

exe:
	g++ -std=c++0x -c AbstractBoard.cpp
	g++ -std=c++0x -c BoardArray1D.cpp
	g++ -std=c++0x -c BoardArray2D.cpp
	g++ -std=c++0x -c BoardVector.cpp
	g++ -std=c++0x -c main.cpp
	g++ -o exe AbstractBoard.o BoardArray1D.o BoardArray2D.o BoardVector.o main.o

clean:
	rm *.o exe
