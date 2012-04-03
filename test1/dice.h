#include <gtkmm/hvbox.h>

class Dice : public Gtk::HBox
{
	
private:
	
	Gtk::Button m_d3_button;
	Gtk::Button m_d4_button;
	Gtk::Button m_d6_button;
	Gtk::Button m_d8_button;
	Gtk::Button m_d10_button;
	Gtk::Button m_d12_button;
	Gtk::Button m_d20_button;
	Gtk::Button m_d100_button;

public:
	int roll(int) const;
	
	


};
