#ifndef WINDOW_H
#define WINDOW_H

#include <gtkmm/window.h>
#include <gtkmm/button.h>
#include "dice.h"

class Window : public Gtk::Window
{
	
private:
	Dice m_dice;
	


public:
	Window();
	virtual ~Window();
	
	

	
	
};

#endif
