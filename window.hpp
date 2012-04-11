/*
 * Layout of widgets:
 *
 * Window
 * |--m_vbox_main
 * |--+--m_hbox_stdButtons
 * |--+--m_hbox_main
 * |--+--|--m_vbox_left
 * |--+--|--+--m_vbox_roll
 * |--+--|--+--|--m_total
 * |--+--|--+--|--m_roll TODO
 * |--+--|--+--m_selectionBox TODO
 * |--+--|--+--m_userDice
 * |--+--|--m_scrolledWindow_log
 * |--+--|--+--m_log
 *
 */

// The main window

#ifndef WINDOW_H
#define WINDOW_H

#include "standardDiceButton.hpp"
#include "userDice.hpp"
#include "buffer.hpp"

// Standard libraries
#include <vector>

// Gtkmm libraries
#include <gtkmm/window.h>
#include <gtkmm/box.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/alignment.h>
#include <gtkmm/textmark.h>



class Window : public Gtk::Window
{
public:
	Window();
	virtual ~Window();
	void print_to_buffer(StandardDiceButton*);
	
	
private:
	Gtk::VBox m_vbox_main;
	Gtk::HBox m_hbox_standardButtons;
	Gtk::HBox m_hbox_main;
	Gtk::VBox m_vbox_left;
	Gtk::TextView m_total;
	Gtk::TextView m_roll; 
//	SelectionBox m_selectionBox TODO
	UserDice m_userDice;
	Gtk::TextView m_log;
	
	Buffer m_buffer;
	
	Gtk::ScrolledWindow m_scrolledWindow_log;
	Gtk::ScrolledWindow m_scrolledWindow_rollPrint;
	
	Gtk::Alignment m_Alignment_fixedTopLeft;
	Gtk::Alignment m_Alignment_scrollableTopLeft;
	
	
	
	int AMOUNT_OF_TOP_BUTTONS;
	StandardDiceButton **m_PtrTopButtons;
	
	
	
	//for scrolling window down
	Glib::RefPtr<Gtk::Adjustment> m_adj;

};


#endif // WINDOW_H
