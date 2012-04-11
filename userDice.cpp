#include "userDice.hpp"

// UserDice implementation
UserDice::UserDice() : m_btn_add("Add")
{
	m_btn_add.signal_clicked().connect(sigc::mem_fun(*this,
		&UserDice::add_new_noname));

	//m_head = NULL;
	m_head = new UserDie("Woot", 10);

	m_vbox.add(m_scrolledWindow);
		m_scrolledWindow.add(*m_head);
	m_vbox.add(m_btn_add);

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
	if (!m_head)
	{
		// This is the first one
		m_head = new UserDie(name, sides);
	}
	else
	{
		UserDie *iter;

		// Find the end.
		for (iter = m_head; iter->m_next != NULL; iter = iter->m_next)
			; // Nothing
			
		// Point end to new node
		iter->m_next = new UserDie(name, sides);

		// Pack new node.
		add(*iter);
		iter->show();
	}
}


// UserDie implementation
UserDice::UserDie::UserDie(const char *name, int sides)
: m_button(name), m_die(sides)
{
	m_next = NULL;

	add(m_button);
	m_button.show();
}

