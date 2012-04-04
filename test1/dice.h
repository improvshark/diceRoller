#ifndef DICE_H
#define DICE_H

#include <gtkmm/hvbox.h>
//#include <gtkmm/hvbuttonbox.h>
#include <gtkmm/grid.h>
#include "die.h"

class Dice : public Gtk::HBox
{
	
private:
	Die m_d3;
	Die m_d4;
	Die m_d6;

public:
	Dice();
	//HBox(bool homogeneous = false,int 	spacing = 0 )		
	//HButtonBox (ButtonBoxStyle layout=BUTTONBOX_EDGE, int spacing=3);
};

#endif
