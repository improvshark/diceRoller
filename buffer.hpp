#ifndef buffer_H
#define buffer_H

#include <string>
#include <gtkmm/textbuffer.h>

class Buffer
{
public:
	Buffer();
	//print a string to the buffer
	void print_to_log(std::string);
	void print_to_total(std::string);
	void print_to_roll(std::string);
	//print an int to the buffer
	void print_to_log(int);
	void print_to_total(int);
	void print_to_roll(int);
	// erase all that is in the buffer
	void clear_log();
	void clear_total();
	void clear_roll();
	// the buffers decleration
	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer_log;
	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer_total;
	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer_roll;
	
	
private:


		
	// the tag and tagTable decleration
	Glib::RefPtr<Gtk::TextBuffer::TagTable> refTagTable;
	Glib::RefPtr<Gtk::TextBuffer::Tag> refTagTotal;
	
	// iterators for the buffers to use
	Gtk::TextBuffer::iterator iterRoll1;
	Gtk::TextBuffer::iterator iterRoll2;
	
		
};

#endif // DIE_H
