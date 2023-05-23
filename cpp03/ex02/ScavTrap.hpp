#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
	ScavTrap();
public:
	ScavTrap(std::string name);
	ScavTrap(ScavTrap& rhs);
	~ScavTrap();

	ScavTrap& operator=(const ScavTrap& rhs);

	void attack (const std::string& target);
	void guardGate();
};

#endif