#ifndef STANDARD_DICE_BUTTONS_H
#define STANDARD_DICE_BUTTONS_H

#include "die.hpp"

// Standard libraries

// Gtkmm libraries
#include <gtkmm/button.h>
#include <glibmm/signalproxy.h>

class StandardDiceButton : public Gtk::Button, public Die
{
public:
	StandardDiceButton(const char*, int = 2);

	
private:

};

#endif // STANDARD_DICE_BUTTONS_H
