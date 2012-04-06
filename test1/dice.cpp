#include "dice.h"

Dice::Dice() 
: Gtk::HBox(true, 15), m_d3("D3", 3), m_d4("D4", 4), m_d6("D6", 6),
m_d8("D8", 8), m_d10("D10", 10), m_d20("D20", 20), m_d100("D100", 100)
{
	
	
	set_size_request(50, 50);
	
	// Add dice
	add(m_d3);
	add(m_d4);
	add(m_d6);
	add(m_d8);
	add(m_d10);
	add(m_d20);
	add(m_d100);
	
	// Show dicema
	m_d3.show();
	m_d4.show();
	m_d6.show();
	m_d8.show();
	m_d10.show();
	m_d20.show();
	m_d100.show();
	
}

void Dice::set_buffer(Gtk::TextBuffer *buffer)
{
	m_refTextBuffer = buffer;
}
