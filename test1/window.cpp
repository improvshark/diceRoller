#include "window.h"
#include "dice.h"

Window::Window()
{
	set_title("DR 5000");
	set_border_width(10);

	add(m_vbox);

	m_refTextBuffer = Gtk::TextBuffer::create();
	m_log.set_editable(false);
	m_log.set_size_request(200, 400);
	m_log.set_buffer(m_refTextBuffer);

	m_vbox.add(m_dice);
	m_vbox.add(m_log);

	m_dice.show();
	m_log.show();
	m_vbox.show();
}

Window::~Window()
{
}

// Prints text onto log's buffer.
void Window::print_to_log(const char *text, int size)
{
	
}
