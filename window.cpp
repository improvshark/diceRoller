#include "window.hpp"
#include <iostream>


Window::Window()
{
	AMOUNT_OF_TOP_BUTTONS = 8;
	
	set_title("DR 5000");
	set_border_width(10);

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
		//m_PtrTopButtons[i]->signal_clicked().connect(sigc::bind<StandardDiceButton*>(sigc::mem_fun(*this,
		//	&::print_to_buffer), m_PtrTopButtons[i]));
		
		m_hbox_standardDiceHolder.add(*m_PtrTopButtons[i]);
		m_PtrTopButtons[i]->set_size_request(50, 50);
		m_PtrTopButtons[i]->show();
	}
	
	m_hbox_standardDiceHolder.set_spacing(15);
	m_Alignment_fixedTopLeft.set(0, 0, 0, 0);
	m_Alignment_scrollableTopLeft.set(0, 0, 0, 1);
	
	
	
	m_log.set_editable(false);
	m_roll.set_editable(false);
	m_scrolledWindow_log.set_size_request(250, 400);
	m_roll.set_size_request(250, 100);
	m_log.set_buffer(Buffer::m_refTextBuffer_log);
	m_roll.set_buffer(Buffer::m_refTextBuffer_total);
	
	m_Alignment_scrollableTopLeft.set_border_width(10);
	m_roll.set_border_width(10);
	
	add(m_vbox_main);
		m_vbox_main.add(m_Alignment_fixedTopLeft);
			m_Alignment_fixedTopLeft.add(m_hbox_standardDiceHolder);
		m_vbox_main.add(m_hbox2);
			m_hbox2.add(m_roll);
			m_hbox2.add(m_Alignment_scrollableTopLeft);
				m_Alignment_scrollableTopLeft.add(m_scrolledWindow_log);
					m_scrolledWindow_log.add(m_log);
				

	m_vbox_main.show();
	m_Alignment_fixedTopLeft.show();
	m_hbox_standardDiceHolder.show();
	m_hbox2.show();
	m_Alignment_scrollableTopLeft.show();
	m_scrolledWindow_log.show();
	m_log.show();
	
	
	show_all_children();

}

Window::~Window()
{
	for (int i = 0; i < 8; i++)
		delete m_PtrTopButtons[i];
	
	delete [] m_PtrTopButtons;
}


