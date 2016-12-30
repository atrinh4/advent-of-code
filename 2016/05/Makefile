CXX=g++
CXXFLAGS=-Wall -Werror -O2 -std=c++14
LDFLAGS=-lcrypto

day05: day05.o
	$(CXX) -o $@ $? $(LDFLAGS)

day05.o: day05.cpp

clean:
	$(RM) *.o *.gch a.out day05
