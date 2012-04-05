#ifndef DICE_H
#define DICE_H

#include <gtkmm/hvbox.h>
#include <gtkmm/grid.h>
#include "die.h"
#include <gtkmm/textview.h>

class Dice : public Gtk::HBox
{
	
private:	
	Die m_d3;
	Die m_d4;
	Die m_d6;
	Die m_d8;
	Die m_d10;
	Die m_d20;
	Die m_d100;
	
	Gtk::TextBuffer *m_refTextBuffer;
	
public:
	Dice();
	

};

#endif
