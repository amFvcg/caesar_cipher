CXX=g++
CXXFLAGS=-c -Wall -std=c++11 -Werror -O2
EXECUTABLE=rot47

all: rot47

rot47: main.o
	$(CXX) main.o -o $(EXECUTABLE)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

clean:
	rm -f *o $(EXECUTABLE)
