#include "userDice.hpp"

// UserDice implementation
UserDice::UserDice() : m_btn_add("Add")
{
	m_head = new Head;

	//m_head->next = NULL;
	m_head->m_next = new UserDie("Woot", 10, m_head);

	m_btn_add.signal_clicked().connect(sigc::mem_fun(*this,
		&UserDice::add_new_noname));

	m_btn_add.set_size_request(10, 10);

	pack_start(m_scrolledWindow, Gtk::PACK_EXPAND_WIDGET, 10);
		m_scrolledWindow.add(m_vbox);
			m_vbox.pack_start(*m_head->m_next, Gtk::PACK_SHRINK );
	pack_start(m_btn_add, Gtk::PACK_SHRINK, 5); 

	m_head->m_next->show();
	m_btn_add.show();
	m_scrolledWindow.show();
	m_vbox.show();
}

UserDice::~UserDice()
{
	do
	{
		if (m_head->m_next == NULL) // If there are no nodes to delete
			break; // Don't do any deleting.

		// Look at the first node.
		UserDie *iter = m_head->m_next;
		
		// m_head->m_next looks at the next one.
		m_head->m_next = iter->m_next;

		// Delete the current one
		delete iter;
	}
	while (m_head->m_next); // While there are still nodes

	// Deallocate m_head
	delete m_head;
}

void UserDice::add_new_noname()
{
	add_new("Foo", 20);
}

// Append a new userDie to the list.
void UserDice::add_new(const char *name, int sides)
{
	UserDie *iter = m_head->m_next;

	if (!iter)
	{
		// This is the first one
		iter = new UserDie(name, sides, m_head);
	}
	else
	{
		// Find the end.
		for (iter = m_head->m_next; iter->m_next != NULL; iter = iter->m_next)
			; // Nothing
			
		// Point end to new node
		iter->m_next = new UserDie(name, sides, m_head);
		iter->m_next->m_prev = iter; // Point to the previous node
	}

	// Pack new node.
	m_vbox.pack_start(*iter, Gtk::PACK_SHRINK , 2);
	iter->show();
}

////////////////////////////////////////////////////////////
// UserDie implementation
////////////////////////////////////////////////////////////

// Constructor
UserDice::UserDie::UserDie(const char *name, int sides, Head *parent)
: m_button(name), m_btn_delete("X"), m_die(sides)
{
	m_parent_head = parent; // Point to head.

	m_hbox.set_size_request(200, 10);
	m_button.set_size_request(200, 10);

	// Connect the delete button to the remove() function.
	m_btn_delete.signal_clicked().connect(sigc::mem_fun(*this,
			&UserDice::UserDie::remove));
	
	m_next = NULL;
	m_prev = NULL;

	pack_start(m_hbox, Gtk::PACK_SHRINK );
		m_hbox.pack_start(m_button, Gtk::PACK_EXPAND_PADDING, 5);
		m_hbox.pack_start(m_btn_delete, Gtk::PACK_EXPAND_PADDING);
	
	m_button.show();
	m_btn_delete.show();
	m_hbox.show();
}

// Deletes itself
void UserDice::UserDie::remove()
{
	// If this is the first node
	if (!m_prev)
		m_parent_head->m_next = NULL;

	// If there isn't a next node, make previous node point to nowhere.
	if (!m_next)
		m_prev = NULL;
	else // There is a next node
	{
		// Make the previous node point to the next node.
		m_prev->m_next = m_next;

		// Make the next node point to the previous node.
		m_next->m_prev = m_prev;
	}

	// Delete this
	delete this;
}

