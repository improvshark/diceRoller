#ifndef buffer_H
#define buffer_H

#include <string>
#include <gtkmm/textbuffer.h>

class Buffer
{
public:
	Buffer();
	void print_to_log(std::string);
	void print_to_total(std::string);
	void print_to_log(int);
	void print_to_total(int);
	
	void clear_log();
	
	void clear_total();
	
	static Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer_log;
	static Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer_total;
	
	
private:


	

	Glib::RefPtr<Gtk::TextBuffer::TagTable> refTagTable;
	Glib::RefPtr<Gtk::TextBuffer::Tag> refTagTotal;
	
	
	
	Gtk::TextBuffer::iterator iter1;
	Gtk::TextBuffer::iterator iter2;
	
	Gtk::TextBuffer::iterator iterRoll1;
	Gtk::TextBuffer::iterator iterRoll2;
	
		
};

#endif // DIE_H