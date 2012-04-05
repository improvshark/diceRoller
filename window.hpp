// The main window

#ifndef WINDOW_H
#define WINDOW_H

#include "standardDiceButton.hpp"

// Standard libraries
#include <vector>

// Gtkmm libraries
#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>

class Window : public Gtk::Window
{
public:
	Window();
	
private:
	Gtk::HBox m_hbox;
	Gtk::VBox m_vbox;
	
	
};


#endif // WINDOW_H
