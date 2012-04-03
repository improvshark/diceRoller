#include <gtkmm/window.h>
#include <gtkmm/button.h>

class Window : public Gtk::Window
{
public:
	Window();
	virtual ~Window();
	
	void on_button_clicked() const;

private:
	Gtk::Button m_button;
	
};
