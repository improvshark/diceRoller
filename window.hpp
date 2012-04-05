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
	virtual ~Window();
	
private:
	Gtk::HBox m_hbox;
	Gtk::VBox m_vbox;

	int AMOUNT_OF_TOP_BUTTONS;
	StandardDiceButton **m_PtrTopButtons;
};


#endif // WINDOW_H
