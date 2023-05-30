#include "Animal.hpp"

Animal::Animal()
{
	this->type = "animal";
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type)
{
	this->type = type;
	std::cout << "Animal " << this->type << " constructor called" << std::endl;
}

Animal::Animal(Animal& rhs)
{
	this->type = rhs.type;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	this->type = rhs.type;
	std::cout << "Animal assignment operator called" << std::endl;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

std::string Animal::getType() const
{
	return this->type;
}