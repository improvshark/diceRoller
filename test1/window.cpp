#include "window.h"
#include "dice.h"
#include "logBuffer.h"

Window::Window() 
{
	set_title("DR 5000");
	set_border_width(10);

	add(m_vbox);

	m_log.set_editable(false);
	m_log.set_size_request(100, 400);
	m_log.set_buffer(m_refTextBuffer1);
	m_vbox.add(m_dice);
	m_vbox.add(m_log);

	m_dice.show();
	m_log.show();
	m_vbox.show();
}

Window::~Window()
{
	//delete m_refTextBuffer;
}
