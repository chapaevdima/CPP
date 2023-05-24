#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << this->type << " constructor called" << std::endl;
	this->brain = new Brain();
}

Cat::~Cat()
{
	std::cout << this->type << " destructor called" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat& rhs)
{
	*this = rhs;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this != &rhs)
	{
		this->type = rhs.type;
		this->brain = new Brain(*(rhs.brain));
	}
	std::cout << "Cat assignment operator called" << std::endl;
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "meow" << std::endl;
}