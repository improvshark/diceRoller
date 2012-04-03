#include <gtkmm.h>

int main(int argc, char *argv[])
{
	Gtk::Main kit(argc, argv);

	Gtk::Window window;

	Gtk::Button button("helloworld");
	window.add(button);
	button.show();
	
	
	
	Gtk::Main::run(window);
	

	return EXIT_SUCCESS;
}
