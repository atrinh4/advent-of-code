CXX=g++
CXXFLAGS=-Wall -Werror -O2 -std=c++14

day01: day01.o
	$(CXX) -o $@ $?

day01.o: day01.cpp day01.h

clean:
	$(RM) *.o *.gch a.out day01
