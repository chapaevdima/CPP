#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_value = rhs.getRawBits();
	//*this = rhs;
}

Fixed& Fixed::operator=(Fixed& rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		this->fixed_point_value = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}