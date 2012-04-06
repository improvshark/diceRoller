// The main window

#ifndef WINDOW_H
#define WINDOW_H

#include "standardDiceButton.hpp"

// Standard libraries
#include <vector>

// Gtkmm libraries
#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/textview.h>

class Window : public Gtk::Window
{
public:
	Window();
	virtual ~Window();

	void print_to_buffer(StandardDiceButton*);
	
private:
	Gtk::HBox m_hbox;
	Gtk::VBox m_vbox;
	
	
	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1;
	Gtk::TextView m_log;
	
	int AMOUNT_OF_TOP_BUTTONS;
	StandardDiceButton **m_PtrTopButtons;
};


#endif // WINDOW_H
