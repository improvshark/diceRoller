#include "window.hpp"

Window::Window()
{
	set_title("DR 5000");
	set_size_request(400, 400);

	m_vbox.add(m_hbox);
	add(m_vbox);

	m_hbox.show();
	m_vbox.show();

}
