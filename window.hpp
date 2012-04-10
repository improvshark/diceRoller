/*
 * Layout of widgets:
 *
 * Window
 * |--m_vbox
 * |--+--m_hbox
 * |--+--|--m_stdbuttons
 * |--+--m_hbox2
 * |--+--|--m_vbox2
 * |--+--|--+--m_vbox3
 * |--+--|--+--|--m_roll
 * |--+--|--+--|--m_roll2
 * |--+--|--+--m_selectionBox
 * |--+--|--+--m_scrollBox2
 * |--+--|--+--|--m_vbox4
 * |--+--|--+--|--+--m_userDice
 * |--+--|--m_scrolledWindow_log
 * |--+--|--+--m_log
 *
 */

// The main window

#ifndef WINDOW_H
#define WINDOW_H

#include "standardDiceButton.hpp"
#include "buffer.hpp"

// Standard libraries
#include <vector>

// Gtkmm libraries
#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/alignment.h>
#include <gtkmm/textmark.h>



class Window : public Gtk::Window
{
public:
	Window();
	virtual ~Window();
	
	
private:
	void print_to_buffer(StandardDiceButton*);

	Gtk::HBox m_hbox_standardDiceHolder;
	Gtk::HBox m_hbox2;
	Gtk::VBox m_vbox_main;
	Gtk::ScrolledWindow m_scrolledWindow_log;
	Gtk::ScrolledWindow m_scrolledWindow_rollPrint;
	
	Gtk::Alignment m_Alignment_fixedTopLeft;
	Gtk::Alignment m_Alignment_scrollableTopLeft;
	
	
	Gtk::TextView m_log;
	Gtk::TextView m_roll;
	
	int AMOUNT_OF_TOP_BUTTONS;
	StandardDiceButton **m_PtrTopButtons;
	
	
	
	//for scrolling window down
	Glib::RefPtr<Gtk::Adjustment> m_adj;

};


#endif // WINDOW_H
