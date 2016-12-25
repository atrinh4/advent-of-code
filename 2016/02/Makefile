CXX=g++
CXXFLAGS=-Wall -Werror -O2 -std=c++14

day02: day02.o
	$(CXX) -o $@ $?

day02.o: day02.cpp day02.h

clean:
	$(RM) *.o *.gch a.out day02
