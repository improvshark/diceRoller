#include "window.h"
#include "dice.h"
#include <gtkmm/textview.h>

LogBuffer::LogBuffer()
{
	m_logBuffer = Gtk::TextBuffer;
}

LogBuffer::~LogBuffer()
{
	delete m_logBuffer;
}
