CXXFLAGS=`pkg-config gtkmm-3.0 --cflags`
LIBS=`pkg-config gtkmm-3.0 --libs`

all: main

main: main.o window.o dice.o die.o
	g++ *o -o main $(LIBS)

main.o: main.cpp
	g++ -c main.cpp $(CXXFLAGS)

window.o: window.cpp window.h
	g++ -c window.cpp $(CXXFLAGS)
	
dice.o: dice.cpp dice.h die.h
	g++ -c dice.cpp $(CXXFLAGS)

die.o: die.cpp die.h
	g++ -c die.cpp $(CXXFLAGS)

clean:
	rm -rf *o main
