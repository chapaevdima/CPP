#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

#include "Weapon.hpp"

class HumanA
{
private:
    Weapon& _weapon;
    std::string name;
public:
    HumanA(std::string name, Weapon& weapon);
    ~HumanA();
    void attack(void);
};

#endif