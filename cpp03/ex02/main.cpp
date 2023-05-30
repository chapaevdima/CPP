#include "FragTrap.hpp"

int main (void)
{
	FragTrap dima_1("dima");
	FragTrap dima_2(dima_1);
	dima_1.attack("kirill");
	dima_1.highFivesGuys();
	dima_2.beRepaired(10);
	dima_2.takeDamage(5);
	for (int i = 0; i < 15; i++)
	{
		dima_1.attack("kirill");
		dima_2.takeDamage(20);
		dima_2.attack("kirill");
	}
	dima_2.highFivesGuys();
	return 0;
}