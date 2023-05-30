#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << this->type << " constructor called" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << this->type << " destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat& rhs)
{
	*this = rhs;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	this->type = rhs.getType();
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "meow" << std::endl;
}