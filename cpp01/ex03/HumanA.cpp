#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _weapon(weapon)
{
    this->name = name;
}

HumanA::~HumanA()
{

}

void HumanA::attack(void)
{
    std::cout << this->name << " attacks with their " << this->_weapon.getType() << std::endl;
    if (this->_weapon.getType() == "")
        std::cout << "(type of his weapon is empty)" << std::endl;
}