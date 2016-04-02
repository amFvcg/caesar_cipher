CXX=g++
CXXFLAGS=-c -Wall -std=c++11 -Werror -O2
INC=-I../include
EXECUTABLE=rot47

all: rot47

rot47: main_rot47.o
	$(CXX) main_rot47.o -o $(EXECUTABLE)

main_rot47.o: main_rot47.cpp
	$(CXX) $(CXXFLAGS) $(INC) main_rot47.cpp

clean:
	rm -f *o $(EXECUTABLE)
