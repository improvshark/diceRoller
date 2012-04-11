#include "buffer.hpp"

Buffer::Buffer()
{
	
	//creation of the tag table and tag to format the total
	refTagTable = Gtk::TextBuffer::TagTable::create();
	refTagTotal = Gtk::TextBuffer::Tag::create();
	//adding the tag to the tag table
	refTagTable->add(refTagTotal);
	// settings for the tag
	refTagTotal->property_foreground () = "blue";
	refTagTotal->property_justification() = Gtk::JUSTIFY_CENTER;
	refTagTotal->property_scale () = 3;
	
	//creating the buffers
	m_refTextBuffer_log = Gtk::TextBuffer::create();
	m_refTextBuffer_total = Gtk::TextBuffer::create(refTagTable);
	m_refTextBuffer_roll = Gtk::TextBuffer::create();
	// telling log to start out with some text: may remove later
	m_refTextBuffer_log->set_text("Log\n");
	
}



void Buffer::print_to_log(std::string arg)
{
	Gtk::TextBuffer::iterator iter = m_refTextBuffer_log->end();

	//append  to end of buffer
	m_refTextBuffer_log->insert(iter, arg + "\n" );	
}

void Buffer::print_to_total(std::string arg)
{
	clear_total();	
	iterRoll1 = m_refTextBuffer_total->begin();
	m_refTextBuffer_total->insert_with_tag(iterRoll1, arg + "\n", refTagTotal);
}

void Buffer::print_to_roll(std::string arg)
{
	
	m_refTextBuffer_roll->set_text(arg);

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
}

void Buffer::print_to_roll(int arg)
{
		//convert to string
	std::stringstream strm;
	std::string num;
	strm << arg;
	strm >> num;
	
	m_refTextBuffer_roll->set_text(num);
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

void Buffer::clear_roll()
{
	iterRoll1 = m_refTextBuffer_total->begin();
	iterRoll2 = m_refTextBuffer_total->end();
	m_refTextBuffer_roll->Gtk::TextBuffer::erase	(iterRoll1, iterRoll2);	
}
