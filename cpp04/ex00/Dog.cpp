#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << this->type << " constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->type << " destructor called" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "woof" << std::endl;
}