#include "ClapTrap.hpp"

int main (void)
{
	ClapTrap dima_1("dima");
	ClapTrap dima_2(dima_1);
	dima_1.attack("sasha");
	dima_2.beRepaired(10);
	dima_2.takeDamage(5);
	for (int i = 0; i < 15; i++)
	{
		dima_1.attack("sasha");
		dima_2.takeDamage(5);
	}
	return 0;
}