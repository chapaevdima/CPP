#ifndef CLAP_TRAP_HPP
# define CLAP_TRAP_HPP

# include <iostream>

class ClapTrap
{
private:
	ClapTrap();

protected:
	std::string name;
	unsigned int hp;
	unsigned int energy;
	unsigned int damage;

public:
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& rhs);
	~ClapTrap();
	ClapTrap& operator=(const ClapTrap& rhs);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif