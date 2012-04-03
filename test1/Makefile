CXXFLAGS=`pkg-config gtkmm-3.0 --cflags`
LIBS=`pkg-config gtkmm-3.0 --libs`

all: main

main: main.o
	g++ *o -o main $(LIBS)

main.o: main.cpp
	g++ -c main.cpp $(CXXFLAGS)

clean:
	rm -rf *o main
