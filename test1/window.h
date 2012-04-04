#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm/window.h>
#include "dice.h"
#include "logBuffer.h"

class Window : public Gtk::Window
{

private:
	Gtk::VBox m_vbox;
	Dice m_dice;
	LogBuffer m_logBuffer;
	Gtk::TextView m_log;

public:
	Window();
	virtual ~Window();


};

#endif
