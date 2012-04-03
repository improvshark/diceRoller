#include "dice.h"


dice:Dice()
: m_d3_button("d3"), m_d4_button("d4")
{




srand ( time(NULL));

void Dice::roll(int arg) const
{
	int diceRoll;
	diceRoll = rand() % arg + 1;
	std::cout << diceRoll << std::endl;
}
