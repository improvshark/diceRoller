#ifndef DIE_H
#define DIE_H

#include <gtkmm/button.h>
#include <gtkmm/textview.h>
class Die : public Gtk::Button
{
public:
	Die(const char*, int = 2);
	void roll() const;
	
private:
	int m_sides;

	//Gtk::TextBuffer *m_refTextBuffer;
};

#endif
