#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << this->type << " constructor called" << std::endl;
	this->brain = new Brain();
}

Dog::~Dog()
{
	std::cout << this->type << " destructor called" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog& rhs)
{
	*this = rhs;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain(*(rhs.brain));
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "woof" << std::endl;
}