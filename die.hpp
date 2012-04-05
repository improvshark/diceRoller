#ifndef DIE_H
#define DIE_H
class Die : public Gtk::Button
{
public:
	Die(const char*, int = 2);
	void roll() const;
	
private:
	int m_sides;
	
};

#endif
