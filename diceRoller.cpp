#include "window.hpp"

// Gtkmm libraries
#include <gtkmm/main.h>

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	Window window;

	Gtk::Main::run(window);

	return EXIT_SUCCESS;
}
