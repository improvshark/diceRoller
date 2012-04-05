/*
 * Has a buffer and ways to access it.
 *
 * logBufferAccess.h
 */

#ifndef LOGBUFFERACCESS_H
#define LOGBUFFERACCESS_H

#include <gtkmm/textview.h>

class LogBufferAccess
{
public:
	LogBufferAccess();
	virtual ~LogBufferAccess();

	void append(const char *);
 
private:
	Glib::RefPtr<Gtk::TextBuffer> m_logBuffer;

};


#endif
