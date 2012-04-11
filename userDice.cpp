#include "userDice.hpp"

// UserDice implementation
UserDice::UserDice()
{
	//m_head = NULL;
	m_head = new UserDie;

	add(*m_head);

	m_head->show();
}

UserDice::~UserDice()
{
	// Delete all the nodes
	delete m_head;
}


// UserDie implementation
UserDice::UserDie::UserDie() : m_button("Woot")
{
	add(m_button);
	m_button.show();
}
