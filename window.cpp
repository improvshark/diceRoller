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
		
		m_hbox_standardDiceHolder.add(*m_PtrTopButtons[i]);
		m_PtrTopButtons[i]->set_size_request(50, 50);
		m_PtrTopButtons[i]->show();
	}
	
	m_hbox_standardDiceHolder.set_spacing(15);
	m_Alignment_fixedTopLeft.set(0, 0, 0, 0);
	m_Alignment_scrollableTopLeft.set(0, 0, 0, 1);
	


	//stuff for formating the text use tags to format and mark to keep position.
	refTagTable = Gtk::TextBuffer::TagTable::create();
	refTagMatch = Gtk::TextBuffer::Tag::create();
	
	refTagTable->add(refTagMatch);
	
	

	
	
	refTagMatch->property_foreground () = "blue";
	refTagMatch->property_justification() = Gtk::JUSTIFY_CENTER;



	
	refTagMatch->property_scale () = 3;
	
	m_refTextBuffer_log = Gtk::TextBuffer::create();
	m_refTextBuffer_roll = Gtk::TextBuffer::create(refTagTable);
	
	m_refTextBuffer_log->set_text("\n\n\nhello world");
	
	iter1 = m_refTextBuffer_log->begin();
	iter2 = m_refTextBuffer_log->end();
	
	iterRoll1 = m_refTextBuffer_roll->begin();
	iterRoll2 = m_refTextBuffer_roll->end();
	
	
	//m_scrolledWindow_log.set_kinetic_scrolling(true);
	
	
	m_log.set_editable(false);
	m_roll.set_editable(false);
	m_scrolledWindow_log.set_size_request(250, 400);
	m_roll.set_size_request(250, 100);
	m_log.set_buffer(m_refTextBuffer_log);
	m_roll.set_buffer(m_refTextBuffer_roll);
	
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

void Window::print_to_buffer(StandardDiceButton *arg)
{
	Gtk::TextBuffer::iterator iter = m_refTextBuffer_log->end();
	
	//std::cout << arg->roll() << std::endl;
	std::stringstream strm;
	std::string num;
	strm << arg->roll();
	strm >> num;
	
	m_refTextBuffer_log->insert(iter, num + "\n" );
	
	
	iterRoll1 = m_refTextBuffer_roll->begin();
	iterRoll2 = m_refTextBuffer_roll->end();
	m_refTextBuffer_roll->Gtk::TextBuffer::erase	(iterRoll1, iterRoll2);	
	iterRoll1 = m_refTextBuffer_roll->begin();
	m_refTextBuffer_roll->insert_with_tag(iterRoll1, num + "\n", refTagMatch);
	

	m_adj = m_scrolledWindow_log.get_vadjustment();
	m_adj->set_value(m_adj->get_upper()); 
	
	
}

