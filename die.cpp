#include "die.hpp"
#include <ctime>
#include <stdlib.h>
#include <iostream>

Die::Die(int sides)
{
	srand( time(NULL) );

	setSides(sides);
}

int Die::roll() const
{
	return rand() % m_sides + 1;
}

void Die::setSides(int sides)
{
	m_sides = sides >= 2 ? sides : 2;
}
