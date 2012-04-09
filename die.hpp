#ifndef DIE_H
#define DIE_H

#include "window.hpp"

class Die
{
public:
	Die(int = 2);
	int roll() const;

	int getSides() const;
	void setSides(int);
	void printRoll(int);
	void setWindow(Window*);
	
private:
	int m_sides;
	Window *m_window;
	
};

#endif // DIE_H
