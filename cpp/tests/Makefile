CXX=g++
CXXFLAGS=-c -Wall -std=c++11 -Werror -O2
LDFLAGS=-lgtest
INC=-I../include
BINARIES=test_rot47XXX

all: $(BINARIES)

test_rot47XXX: test_rot47XXX.o
	$(CXX) $(LDFLAGS) $< -o $@

test_rot47XXX.o: test_rot47XXX.cpp
	$(CXX) $(CXXFLAGS) $(INC) $<

clean:
	rm -f *o $(BINARIES)
