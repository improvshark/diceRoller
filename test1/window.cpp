#include "window.h"
#include <iostream>

Window::Window()
: m_button("Hello")
{
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
	std::cout << "Hello World!\n" << std::endl;
}
