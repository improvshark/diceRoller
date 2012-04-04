#include "die.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>

Die::Die(const char *name, int sides) : Gtk::Button(name)
{
	
	// make btns square
	set_size_request(50, 50); 
	
	// set seed for random number
	srand ( time(NULL));
	
	// Make sure there are at least 2 sides
	m_sides = sides >= 2 ? sides : 2;
	
	// Roll when button gets clicked
	signal_clicked().connect(sigc::mem_fun(*this,
		&Die::roll));
}

// Returns die roll
void Die::roll() const
{
	std::cout << rand() % m_sides + 1 << std::endl;
}
