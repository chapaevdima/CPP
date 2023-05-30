#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << this->type << " constructor called" << std::endl;
}

Dog::~Dog()
{
	std::cout << this->type << " destructor called" << std::endl;
}

Dog::Dog(const Dog& rhs)
{
	*this = rhs;
}

Dog& Dog::operator=(const Dog& rhs)
{
	this->type = rhs.getType();
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "woof" << std::endl;
}