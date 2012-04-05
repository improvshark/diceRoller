LIBS = `pkg-config gtkmm-3.0 --libs`
CFLAGS= `pkg-config gtkmm-3.0 --cflags`

all: diceRoller

diceRoller: diceRoller.o window.o
	g++ *o -o diceRoller $(LIBS)

diceRoller.o: diceRoller.cpp
	g++ -c diceRoller.cpp $(CFLAGS)

window.o: window.cpp window.hpp
	g++ -c window.cpp $(CFLAGS)

clean:
	rm -rf *o diceRoller
