#include "Zombie.hpp"

int main (void)
{
    std::string name;
    std::cout << "Creating zombie on stack" << std::endl;
    std::cout << "Zombie name: ";
    std::cin >> name;

    Zombie zombie_1(name);

    std::cout << "Creating zombie on heap" << std::endl;
    std::cout << "Zombie name: ";
    std::cin >> name;

    Zombie *zombie_2 = newZombie(name);
    zombie_2->announce();
    delete zombie_2;

    std::cout << "Calling randomChump()" << std::endl;
    randomChump("Random");
    return 0;
}