#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hp = 10;
	this->energy = 10;
	this->damage = 10;
	std::cout << "ClapTrap " << this->name << " is born" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called (ClapTrap)" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& rhs)
{
	std::cout << "Copy constructor called (ClapTrap)" << std::endl;
	*this = rhs;
}

ClapTrap& ClapTrap:: operator=(const ClapTrap& rhs)
{
	this->damage = rhs.damage;
	this->energy = rhs.energy;
	this->hp = rhs.hp;
	this->name = rhs.name;
	std::cout << "ClapTrap " << this->name << " has been copied with assignment operator" << std::endl;
	return *this;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hp <= amount)
	{
		std::cout << this->name << " is dead" << std::endl;
		this->hp = 0;	
		return;	
	}
	std::cout << this->name << " takes " << amount << " damage" << std::endl;
	this->hp -= amount;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->hp <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead" << std::endl;	
		return;	
	}
	if (this->energy <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is out of energy" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacking " << target << ", dealing " << this->damage << " damage" << std::endl;
	energy -= 1;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hp <= 0)
	{
		std::cout << this->name << " is dead" << std::endl;	
		return;	
	}
	if (this->energy <= 0)
	{
		std::cout << this->name << " is out of energy" << std::endl;
		return;
	}
	std::cout << this->name << " repairs itself for " << amount << "HP" << std::endl;
	this->energy -= 1;
	this->hp += amount;
}
