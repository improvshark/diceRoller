#ifndef USERDICE_HPP
#define USERDICE_HPP

#include "die.hpp"

// Gtkmm libs
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/button.h>

class UserDice : public Gtk::ScrolledWindow
{
public:
	UserDice();
	virtual ~UserDice();

	void add_new(const char*, int);

private:

	class UserDie : public Gtk::HBox
	{
	public:
		UserDie(const char*, int);

	private:
		Gtk::Button m_button;
		Die m_die;

		UserDie *m_next;
	};

	UserDie *m_head;
};


#endif // USERDICE_HPP
