#include <gtkmm/main.h>
#include "window.h"

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);
	
	Window window;
	
	
	Gtk::Main::run(window);
	return EXIT_SUCCESS;
}
