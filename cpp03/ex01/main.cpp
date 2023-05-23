#include "ScavTrap.hpp"

int main (void)
{
	ScavTrap dima_1("dima");
	ScavTrap dima_2(dima_1);
	dima_1.attack("sasha");
	dima_2.beRepaired(10);
	dima_2.takeDamage(5);
	for (int i = 0; i < 15; i++)
	{
		dima_1.attack("sasha");
		dima_2.takeDamage(20);
	}
	return 0;
}