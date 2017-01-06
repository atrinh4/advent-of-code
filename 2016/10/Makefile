CXX=g++
CXXFLAGS=-Wall -Werror -O2 -std=c++14

day10: day10.o
	$(CXX) -o $@ $?

day10.o: day10.cpp day10.h

clean:
	$(RM) *.o *.gch a.out day10
