#include "window.h"
#include "dice.h"
#include <gtkmm/textview.h>

LogBufferAccess::LogBufferAccess()
{
	m_logBuffer = Gtk::TextBuffer::create();
}

LogBufferAccess::~LogBufferAccess()
{
}
