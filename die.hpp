#ifndef DIE_H
#define DIE_H

class Die
{
public:
	Die(int = 2);
	int roll() const;

	int getSides() const;
	void setSides(int);
	
private:
	int m_sides;
	
};

#endif // DIE_H
