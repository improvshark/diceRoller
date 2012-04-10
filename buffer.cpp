#include "buffer.hpp"

Buffer::Buffer()
{
	
	//stuff for formating the text use tags to format and mark to keep position.
	refTagTable = Gtk::TextBuffer::TagTable::create();
	refTagTotal = Gtk::TextBuffer::Tag::create();
	
	refTagTable->add(refTagTotal);
	
	

	
	
	refTagTotal->property_foreground () = "blue";
	refTagTotal->property_justification() = Gtk::JUSTIFY_CENTER;



	
	refTagTotal->property_scale () = 3;
	
	m_refTextBuffer_log = Gtk::TextBuffer::create();
	m_refTextBuffer_total = Gtk::TextBuffer::create(refTagTable);
	
	m_refTextBuffer_log->set_text("\n\n\nhello world");
	
	iter1 = m_refTextBuffer_log->begin();
	iter2 = m_refTextBuffer_log->end();
	
	iterRoll1 = m_refTextBuffer_total->begin();
	iterRoll2 = m_refTextBuffer_total->end();
	
}



void Buffer::print_to_log(std::string arg)
{
	Gtk::TextBuffer::iterator iter = m_refTextBuffer_log->end();

	//append  to end of buffer
	m_refTextBuffer_log->insert(iter, arg "\n" );

	//scroll window down a bit
	m_adj = m_scrolledWindow_log.get_vadjustment();
	m_adj->set_value(m_adj->get_upper()); 
	
	
}

void Buffer::print_to_log(int arg)
{
	Gtk::TextBuffer::iterator iter = m_refTextBuffer_log->end();
	
	//convert to string
	std::stringstream strm;
	std::string num;
	strm << arg;
	strm >> num;
	
	//append to end of buffer
	m_refTextBuffer_log->insert(iter, num + "\n" );

	//scroll window down a bit
	m_adj = m_scrolledWindow_log.get_vadjustment();
	m_adj->set_value(m_adj->get_upper()); 
	
	
}

void Buffer::print_to_total(std::string arg)
{
	iterRoll1 = m_refTextBuffer_total->begin();
	iterRoll2 = m_refTextBuffer_total->end();
	m_refTextBuffer_total->Gtk::TextBuffer::erase	(iterRoll1, iterRoll2);	
	iterRoll1 = m_refTextBuffer_total->begin();
	m_refTextBuffer_total->insert_with_tag(iterRoll1, arg + "\n", refTagTotal);
	
	//scroll window down a bit
	m_adj = m_scrolledWindow_log.get_vadjustment();
	m_adj->set_value(m_adj->get_upper()); 
	
	
}

void Buffer::print_to_total(int arg)
{
		//convert to string
	std::stringstream strm;
	std::string num;
	strm << arg;
	strm >> num;
	
	
	iterRoll1 = m_refTextBuffer_total->begin();
	iterRoll2 = m_refTextBuffer_total->end();
	m_refTextBuffer_total->Gtk::TextBuffer::erase	(iterRoll1, iterRoll2);	
	iterRoll1 = m_refTextBuffer_total->begin();
	m_refTextBuffer_total->insert_with_tag(iterRoll1, num + "\n", refTagTotal);
	
	//scroll window down a bit
	m_adj = m_scrolledWindow_log.get_vadjustment();
	m_adj->set_value(m_adj->get_upper()); 
	
	
}

void Buffer::clear_log()
{
	iterRoll1 = m_refTextBuffer_total->begin();
	iterRoll2 = m_refTextBuffer_total->end();
	m_refTextBuffer_log->Gtk::TextBuffer::erase	(iterRoll1, iterRoll2);	
}

void Buffer::clear_total()
{
	iterRoll1 = m_refTextBuffer_total->begin();
	iterRoll2 = m_refTextBuffer_total->end();
	m_refTextBuffer_total->Gtk::TextBuffer::erase	(iterRoll1, iterRoll2);	
}
