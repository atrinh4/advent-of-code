CXX=g++
CXXFLAGS=-Wall -Werror -O2 -std=c++14

day03: day03.o
	$(CXX) -o $@ $?

day03.o: day03.cpp

clean:
	$(RM) *.o *.gch a.out day03
