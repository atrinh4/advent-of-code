CXX=g++
CXXFLAGS=-Wall -Werror -O2 -std=c++14

day08: day08.o
	$(CXX) -o $@ $?

day08.o: day08.cpp day08.h

clean:
	$(RM) *.o *.gch a.out day08
