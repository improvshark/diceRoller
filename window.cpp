#include "window.hpp"
#include <iostream>


Window::Window()
{
	AMOUNT_OF_TOP_BUTTONS = 8;
	
	set_title("DR 5000");
	set_border_width(10);
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
		m_PtrTopButtons[i]->signal_clicked().connect(sigc::bind<StandardDiceButton*>(sigc::mem_fun(*this,
			&Window::print_to_buffer), m_PtrTopButtons[i]));
		
		m_hbox.add(*m_PtrTopButtons[i]);
		m_PtrTopButtons[i]->set_size_request(50, 50);
		m_PtrTopButtons[i]->show();
	}
	m_hbox.set_spacing(15);
	add(m_vbox);
	


	//stuff for formating the text use tags to format and mark to keep position.
	refTagTable = Gtk::TextBuffer::TagTable::create();
	refTagMatch = Gtk::TextBuffer::Tag::create();
	
	refTagTable->add(refTagMatch);
	
	Gtk::TextBuffer::iterator iter1;
	Gtk::TextBuffer::iterator iter2;
	
	
	refTagMatch->property_background() = "orange";
	refTagMatch->property_size () = 10;
	
	m_refTextBuffer1 = Gtk::TextBuffer::create(refTagTable);
	m_refTextBuffer1->set_text("This is the text from TextBuffer #1.");
	
	iter1 = m_refTextBuffer1->begin();
	iter2 = m_refTextBuffer1->end();
	
	m_refTextBuffer1->apply_tag(refTagMatch, iter1, iter2);
	
	
	
	

	
	
	
	m_log.set_editable(false);
	m_scrolledWindow.set_size_request(100, 400);
	m_log.set_buffer(m_refTextBuffer1);
	
	m_vbox.add(m_hbox);
	m_hbox2.pack_start(m_scrolledWindow, Gtk::FILL, 0);
	m_vbox.add(m_hbox2);
	m_scrolledWindow.add(m_log);

	m_hbox.show();
	m_hbox2.show();
	m_log.show();
	m_vbox.show();
	m_scrolledWindow.show();
	
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
	Gtk::TextBuffer::iterator iter = m_refTextBuffer1->end();
	
	//std::cout << arg->roll() << std::endl;
	std::stringstream strm;
	std::string num;
	strm << arg->roll();
	strm >> num;
	
	m_refTextBuffer1->insert(iter, num + "\n" );
}

