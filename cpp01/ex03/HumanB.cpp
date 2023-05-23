#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
    this->weapon = NULL;
}

HumanB::~HumanB()
{

}

void HumanB::attack()
{
    if(this->weapon != NULL)
    {
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
        if (this->weapon->getType() == "")
            std::cout << "(type of his weapon is empty)" << std::endl;
    }
    else 
        std::cout << this->name << " doesn't have a weapon" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}