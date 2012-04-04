#include "die.h"
#include "window.h" // So we can print dice rolls to the log.
#include <ctime>
#include <stdlib.h>
#include <iostream>

Die::Die(const char *name, int sides) : Gtk::Button(name)
{
<<<<<<< HEAD
	
	set_size_request(50, 50); // Make buttons square
	
	// set seed for random number
	srand ( time(NULL));
=======

	set_size_request(50, 50); // Make buttons square

	srand( time(NULL) );
>>>>>>> d28686e9c23e97f3532075dfedcd8294e43015c8
	
	// Make sure there are at least 2 sides
	m_sides = sides >= 2 ? sides : 2;
	
	// Roll when button gets clicked
	signal_clicked().connect(sigc::mem_fun(*this,
		&Die::roll));
}


void Die::roll() const
{
	std::cout << rand() % m_sides + 1 << std::endl;
}
