CXX=g++
CXXFLAGS=-c -Wall -std=c++11 -Werror -O2
INC=-Iinclude
BINARIES=rot47 rot47_stepping
DESCRIPTION="Rot47 cipher"

all: rot47 rot47_stepping

rot47.1: rot47
	help2man -o $@ --name=$(DESCRIPTION) ./$<

rot47: main_rot47.o
	$(CXX) $< -o $@ -lboost_program_options

rot47_stepping: main_rot47_stepping.o
	$(CXX) $< -o $@

main_rot47.o: src/main_rot47.cpp
	$(CXX) $(CXXFLAGS) $(INC) $<


main_rot47_stepping.o: src/main_rot47_stepping.cpp
	$(CXX) $(CXXFLAGS) $(INC) $<

clean:
	rm -f *o $(BINARIES) rot47.1
