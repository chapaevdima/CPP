#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hp = 100;
	this->energy = 50;
	this->damage = 20;
	std::cout << "ScavTrap " << this->name << " is born" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& rhs): ClapTrap(rhs)
{
	std::cout << "Copy constructor called (ScavTrap)" << std::endl;
}

ScavTrap& ScavTrap:: operator=(const ScavTrap& rhs)
{
	this->energy = rhs.energy;
	this->damage = rhs.damage;
	this->hp = rhs.hp;
	this->name = rhs.name;
	std::cout << "ScavTrap " << this->name << " has been copied with assignment operator" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor called (ScavTrap)" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->energy <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is out of energy" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacking " << target << ", dealing " << this->damage << " damage" << std::endl;
	energy -= 1;
}

void ScavTrap::guardGate()
{
	if (this->hp <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead" << std::endl;	
		return;	
	}
	std::cout << "ScavTrap " << this->name << "  is now in Gate keeper mode" << std::endl;
}
