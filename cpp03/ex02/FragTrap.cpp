#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hp = 100;
	this->energy = 100;
	this->damage = 30;
	std::cout << "FragTrap " << this->name << " is born" << std::endl;
}

FragTrap::FragTrap(FragTrap& rhs): ClapTrap(rhs)
{
	std::cout << "Copy constructor called (FragTrap)" << std::endl;
}

FragTrap& FragTrap:: operator=(const FragTrap& rhs)
{
	this->energy = rhs.energy;
	this->damage = rhs.damage;
	this->hp = rhs.hp;
	this->name = rhs.name;
	std::cout << "FragTrap " << this->name << " has been copied with assignment operator" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor called (FragTrap)" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " high fives" << std::endl;
}
