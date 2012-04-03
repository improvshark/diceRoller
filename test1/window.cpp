#include "window.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>


Window::Window()
{

	
	
	set_border_width(10);
	
	m_hbox.add(m_d3_button);
	m_hbox.add(m_d4_button);
	
	add(m_dice_hbox);
	
	m_d3_button.signal_clicked().connect(sigc::mem_fun(*this,
		&Window::on_d3_button_clicked));
		
	m_d4_button.signal_clicked().connect(sigc::mem_fun(*this,
		&Window::on_d4_button_clicked));
	
	
	m_d3_button.show();
	m_d4_button.show();
	
	m_hbox.show();
	
}

Window::~Window()
{
}


