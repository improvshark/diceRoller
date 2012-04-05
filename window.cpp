#include "window.hpp"

Window::Window()
{
	AMOUNT_OF_TOP_BUTTONS = 8;
	
	set_title("DR 5000");
	//set_size_request(400, 400);

	m_PtrTopButtons = new StandardDiceButton*[AMOUNT_OF_TOP_BUTTONS];

	m_PtrTopButtons[0] = new StandardDiceButton { "D3", 3 };
	m_PtrTopButtons[1] = new StandardDiceButton { "D4", 4 };
	m_PtrTopButtons[2] = new StandardDiceButton { "D6", 6 };
	m_PtrTopButtons[3] = new StandardDiceButton { "D8", 8 };
	m_PtrTopButtons[4] = new StandardDiceButton { "D10", 10 };
	m_PtrTopButtons[5] = new StandardDiceButton { "D20", 20 };
	m_PtrTopButtons[6] = new StandardDiceButton { "D50", 50 };
	m_PtrTopButtons[7] = new StandardDiceButton { "D100", 100 };
	
	for (int i = 0; i < AMOUNT_OF_TOP_BUTTONS; i++)
	{
		// m_PtrTopButtons[i] = new StandardDiceButton { "D3", i };
		
		m_hbox.add(*m_PtrTopButtons[i]);
		m_PtrTopButtons[i]->set_size_request(50, 50);
		m_PtrTopButtons[i]->show();
	}
	

	m_vbox.add(m_hbox);
	add(m_vbox);

	m_hbox.show();
	m_vbox.show();

}

Window::~Window()
{
	for (int i = 0; i < 8; i++)
		delete m_PtrTopButtons[i];
	
	delete [] m_PtrTopButtons;
}
