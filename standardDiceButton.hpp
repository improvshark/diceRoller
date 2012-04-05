#ifndef STANDARD_DICE_BUTTONS_H
#define STANDARD_DICE_BUTTONS_H

#include "die.hpp"

// Gtkmm libraries
#include <gtkmm/button.h>

class StandardDiceButton : public Gtk::Button
{
public:
	StandardDiceButton(const char*, int = 2);


private:
	Die m_die;

};

#endif // STANDARD_DICE_BUTTONS_H
