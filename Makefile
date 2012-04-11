LIBS = `pkg-config gtkmm-3.0 --libs`
CFLAGS= `pkg-config gtkmm-3.0 --cflags`

all: diceRoller

diceRoller: diceRoller.o window.o standardDiceButton.o die.o buffer.o userDice.o
	g++ *o -o diceRoller $(LIBS)

diceRoller.o: diceRoller.cpp
	g++ -c diceRoller.cpp $(CFLAGS)

window.o: window.cpp window.hpp buffer.hpp
	g++ -c window.cpp $(CFLAGS) -std=gnu++0x

standardDiceButton.o: standardDiceButton.cpp standardDiceButton.hpp
	g++ -c standardDiceButton.cpp $(CFLAGS)

die.o: die.cpp die.hpp
	g++ -c die.cpp $(CFLAGS)
	
buffer.o: buffer.cpp buffer.hpp
	g++ -c buffer.cpp $(CFLAGS)

userDice.o: userDice.cpp userDice.hpp
	g++ -c userDice.cpp $(CFLAGS)

clean:
	rm -rf *o diceRoller
