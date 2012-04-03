#include "window.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>


Window::Window()
: m_button("Hello")
{
	srand ( time(NULL));
	
	add(m_button);
	
	set_border_width(10);
	
	m_button.signal_clicked().connect(sigc::mem_fun(*this,
		&Window::on_button_clicked));
	
	m_button.show();
	
}

Window::~Window()
{
}

void Window::on_button_clicked() const
{
	int diceRoll;
	diceRoll = rand() % 10 + 1;
	std::cout << diceRoll << std::endl;
}
