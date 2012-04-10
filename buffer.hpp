#ifndef buffer_H
#define buffer_H

#include <string>
#include <gtkmm/textbuffer.h>

class Buffer
{
public:
	void print_to_log(std::string);
	void print_to_total(std::string);
	
	void clear_log();
	void clear_total();
	
	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer_log;
	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer_total;
	
	
private:

	Buffer();

	Glib::RefPtr<Gtk::TextBuffer::TagTable> refTagTable;
	Glib::RefPtr<Gtk::TextBuffer::Tag> refTagTotal;
	
	
	
	Gtk::TextBuffer::iterator iter1;
	Gtk::TextBuffer::iterator iter2;
	
	Gtk::TextBuffer::iterator iterRoll1;
	Gtk::TextBuffer::iterator iterRoll2;
	
	
	//for scrolling window down
	Glib::RefPtr<Gtk::Adjustment> m_adj;
	
};

#endif // DIE_H
