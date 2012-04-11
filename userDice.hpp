#ifndef USERDICE_HPP
#define USERDICE_HPP

#include "die.hpp"

// Gtkmm libs
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/button.h>

class UserDice : public Gtk::VBox
{
public:
	UserDice();
	virtual ~UserDice();

	void add_new_noname();
	void add_new(const char*, int);

private:

	class UserDie : public Gtk::HBox
	{
	public:
		UserDie(const char*, int);

		UserDie *m_next;

	private:
		Gtk::HBox m_hbox;
		Gtk::Button m_button;
		Gtk::Button m_btn_delete;

		Die m_die;
	};

	UserDie *m_head;

	// Widgets
	Gtk::ScrolledWindow m_scrolledWindow;
	Gtk::VBox m_vbox;
	Gtk::Button m_btn_add;
};


#endif // USERDICE_HPP
