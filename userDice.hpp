#ifndef USERDICE_HPP
#define USERDICE_HPP

#include <gtkmm/scrolledwindow.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/button.h>

class UserDice : public Gtk::ScrolledWindow
{
public:
	UserDice();
	virtual ~UserDice();

private:

	class UserDie : public Gtk::HBox
	{
	public:
		UserDie();

	private:
		Gtk::Button m_button;
		// Stuff
		UserDie *m_next;

	};

	UserDie *m_head;
};


#endif // USERDICE_HPP
