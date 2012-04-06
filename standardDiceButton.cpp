#include "standardDiceButton.hpp"

StandardDiceButton::StandardDiceButton(const char *name, int sides) : Gtk::Button(name), Die(sides)
{
}
