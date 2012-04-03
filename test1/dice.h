#ifndef DICE_H
#define DICE_H

#include <gtkmm/hvbox.h>
#include "die.h"

class Dice : public Gtk::HBox
{
	
private:
	Die m_d3;
	Die m_d4;

public:
	Dice();

};

#endif
