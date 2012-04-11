#include "userDice.hpp"

// UserDice implementation
UserDice::UserDice() : m_btn_add("Add")
{
	m_btn_add.signal_clicked().connect(sigc::mem_fun(*this,
		&UserDice::add_new_noname));


	m_btn_add.set_size_request(10, 10);
	

	//m_head = NULL;
	m_head = new UserDie("Woot", 10);

	pack_start(m_scrolledWindow, Gtk::PACK_EXPAND_WIDGET, 10);
		m_scrolledWindow.add(m_vbox);
			m_vbox.pack_start(*m_head, Gtk::PACK_SHRINK );
	pack_start(m_btn_add, Gtk::PACK_SHRINK, 5); 

	m_head->show();
	m_btn_add.show();
	m_scrolledWindow.show();
	m_vbox.show();
}

UserDice::~UserDice()
{
	UserDie *iter = NULL;
	UserDie *next = NULL;

	// Find the first node
	iter = m_head;

	// While there are still nodes
	while (iter)
	{
		// next looks at the next node
		next = iter->m_next;

		// Delete the current node
		delete iter;

		// Go to the next node
		iter = next;
	}
}

void UserDice::add_new_noname()
{
	add_new("Foo", 20);
}

// Append a new userDie to the list.
void UserDice::add_new(const char *name, int sides)
{
	UserDie *iter = m_head;

	if (!iter)
	{
		// This is the first one
		iter = new UserDie(name, sides);
	}
	else
	{
		// Find the end.
		for (iter = m_head; iter->m_next != NULL; iter = iter->m_next)
			; // Nothing
			
		// Point end to new node
		iter->m_next = new UserDie(name, sides);
		iter = iter->m_next;
	}

	// Pack new node.
	m_vbox.pack_start(*iter, Gtk::PACK_SHRINK , 2);
	iter->show();
}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

// UserDie implementation
UserDice::UserDie::UserDie(const char *name, int sides)
: m_button(name), m_btn_delete("X"), m_die(sides)
{
	m_hbox.set_size_request(200, 10);
	m_button.set_size_request(200, 10);
	
	m_next = NULL;

	pack_start(m_hbox, Gtk::PACK_SHRINK );
		m_hbox.pack_start(m_button, Gtk::PACK_EXPAND_PADDING, 5);
		m_hbox.pack_start(m_btn_delete, Gtk::PACK_EXPAND_PADDING, 5);
	
	m_button.show();
	m_btn_delete.show();
	m_hbox.show();
}

