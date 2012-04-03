#include "window.h"
#include "dice.h"
#include <iostream>

Window::Window()
{
	set_border_width(10);
	
	add(m_dice);
	

		
	
	
	m_dice.show();
	
}

Window::~Window()
{
}


