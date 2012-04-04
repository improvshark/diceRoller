#include "dice.h"

Dice::Dice() 
: Gtk::HBox(true, 5), m_d3("D3", 3), m_d4("D4", 4), m_d6("D6", 6)
{
	
	
	set_size_request(50, 50);
	
	// Add dice
	add(m_d3);
	add(m_d4);
	add(m_d6);
	
	// Show dice
	m_d3.show();
	m_d4.show();
	m_d6.show();
}
