#include "dice.h"


Dice::Dice()
: m_d3("D3", 3), m_d4("D4", 4)
{
	// Add dice
	add(m_d3);
	add(m_d4);
	
	// Show dice
	m_d3.show();
	m_d4.show();
}
