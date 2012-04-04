#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/textview.h>
#include "dice.h"

class Window : public Gtk::Window
{

private:
	Gtk::VBox m_vbox;
	Gtk::TextView m_log;
	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer;
	Dice m_dice;


public:
	Window();
	virtual ~Window();

	static void print_to_log(const char*, int);

};

#endif
