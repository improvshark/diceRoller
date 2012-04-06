#include "window.h"
#include "dice.h"
#include <gtkmm/textview.h>

LogBuffer::LogBuffer()
{
}

LogBuffer::~LogBuffer()
{
	delete m_logBuffer;
}
