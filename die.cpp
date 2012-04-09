#include "die.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>


Die::Die(int sides)
{
	srand( time(NULL) );
	
	m_window = NULL;

	setSides(sides);
}

int Die::roll() const
{
	return rand() % m_sides + 1;
}

int Die::getSides() const
{
	return m_sides;
}

void Die::setSides(int sides)
{
	m_sides = sides >= 2 ? sides : 2;
}

void Die::printRoll(int arg)
{
	std::stringstream strm;
	std::string num;
	strm << arg;
	strm >> num;
	
	m_window->print_to_log("FOOBAR");
}

void Die::setWindow(Gtk::Window *window)
{
	m_window = window;
}
