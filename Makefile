LIBS = `pkg-config gtkmm-3.0 --libs`
CFLAGS= `pkg-config gtkmm-3.0 --cflags`

all: diceRoller

diceRoller: diceRoller.o window.o standardDiceButton.o die.o
	g++ *o -o diceRoller $(LIBS)

diceRoller.o: diceRoller.cpp
	g++ -c diceRoller.cpp $(CFLAGS)

window.o: window.cpp window.hpp
	g++ -c window.cpp $(CFLAGS) -std=gnu++0x

standardDiceButton.o: standardDiceButton.cpp standardDiceButton.hpp
	g++ -c standardDiceButton.cpp $(CFLAGS)

die.o: die.cpp die.hpp window.hpp
	g++ -c die.cpp $(CFLAGS)

clean:
	rm -rf *o diceRoller
