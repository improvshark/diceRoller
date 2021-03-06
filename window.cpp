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
		m_PtrTopButtons[i]->signal_clicked().connect(sigc::bind<StandardDiceButton*>(sigc::mem_fun(*this,
			&Window::print_to_buffer), m_PtrTopButtons[i]));
		
		m_hbox_standardButtons.pack_start(*m_PtrTopButtons[i], Gtk::PACK_EXPAND_WIDGET, 7.5);
		m_PtrTopButtons[i]->set_size_request(50, 50);
		m_PtrTopButtons[i]->show();
	}
	

	
	
	// make sure the user cant edit the buffers
	m_log.set_editable(false);
	m_total.set_editable(false);
	m_roll.set_editable(false);
	// set the sizes of the textViews and the scrolled window with log
	m_scrolledWindow_log.set_size_request(250, 400);
	m_total.set_size_request(250, 68);
	m_roll.set_size_request(250, 30);
	// set wich buffer each textVeiw will use
	m_log.set_buffer(m_buffer.m_refTextBuffer_log);
	m_total.set_buffer(m_buffer.m_refTextBuffer_total);
	m_roll.set_buffer(m_buffer.m_refTextBuffer_roll);
	
	
	
	// Pack widgets
	add(m_vbox_main);
		m_vbox_main.pack_start(m_hbox_standardButtons, Gtk::PACK_SHRINK, 5);
		m_vbox_main.pack_start(m_hbox_main);
			m_hbox_main.pack_start(m_vbox_left,Gtk::PACK_EXPAND_WIDGET,5);
				m_vbox_left.pack_start(m_total, Gtk::PACK_SHRINK);
				m_vbox_left.pack_start(m_roll, Gtk::PACK_SHRINK, 2); 
//				m_vbox_left.add(m_selectionBox); TODO
				m_vbox_left.add(m_userDice);
			m_hbox_main.pack_start(m_scrolledWindow_log);
				m_scrolledWindow_log.add(m_log);
				


// show all the widgets
	m_log.show();
	m_scrolledWindow_log.show();
	m_userDice.show();
	m_roll.show();
//	m_selectionBox.show() TODO
	m_total.show();
	m_vbox_left.show();
	m_hbox_main.show();
	m_hbox_standardButtons.show();
	m_vbox_main.show();

}

Window::~Window()
{
	// delete all the stdbutton stuff
	for (int i = 0; i < AMOUNT_OF_TOP_BUTTONS; i++)
		delete m_PtrTopButtons[i];
	
	delete [] m_PtrTopButtons;
}


void Window::print_to_buffer(StandardDiceButton *arg)
{
	// roll the die
	int roll = arg->roll();
	// print its result using buffer class
	m_buffer.print_to_log(roll);
	m_buffer.print_to_total(roll);
	m_buffer.print_to_roll(roll);
	
	// Scroll log window down.
	m_adj = m_scrolledWindow_log.get_vadjustment();                                
		m_adj->set_value(m_adj->get_upper());  
	
}
