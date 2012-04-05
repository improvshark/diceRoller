#include "standardDiceButton.hpp"

StandardDiceButton::StandardDiceButton(const char *name, int sides) : m_die(sides), Gtk::Button(name)
{
}
