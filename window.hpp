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

// Standard libraries
#include <vector>

// Gtkmm libraries
#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/textview.h>
#include <gtkmm/alignment.h>


class Window : public Gtk::Window
{
public:
	Window();
	virtual ~Window();

	void print_to_buffer(StandardDiceButton*);
	
private:
	Gtk::HBox m_hbox_standardDiceHolder;
	Gtk::HBox m_hbox2;
	Gtk::VBox m_vbox_main;
	Gtk::ScrolledWindow m_scrolledWindow_log;
	
	
	Glib::RefPtr<Gtk::TextBuffer::TagTable> refTagTable;
	Glib::RefPtr<Gtk::TextBuffer::Tag> refTagMatch;
	Glib::RefPtr<Gtk::TextBuffer> m_refTextBuffer1;
	Gtk::TextBuffer::iterator iter1;
	Gtk::TextBuffer::iterator iter2;
	
	Gtk::Alignment m_Alignment_fixedTopLeft;
	Gtk::Alignment m_Alignment_scrollableTopLeft;
	
	
	Gtk::TextView m_log;
	Gtk::TextView m_roll;
	
	
	int AMOUNT_OF_TOP_BUTTONS;
	StandardDiceButton **m_PtrTopButtons;
};


#endif // WINDOW_H
