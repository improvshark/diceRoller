#include "userDice.hpp"

// UserDice implementation
UserDice::UserDice()
{
	//m_head = NULL;
	m_head = new UserDie("Woot", 10);

	add(*m_head);

	m_head->show();
}

UserDice::~UserDice()
{
	// Delete all the nodes
	delete m_head;
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
		UserDie *newDie = new UserDie(name, sides);

		// Find the end.
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
