#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << this->type << " constructor called" << std::endl;
}

Cat::~Cat()
{
	std::cout << this->type << " destructor called" << std::endl;
}

Cat::Cat(const Cat& rhs)
{
	*this = rhs;
}

Cat& Cat::operator=(const Cat& rhs)
{
	this->type = rhs.getType();
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}