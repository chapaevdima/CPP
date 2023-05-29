#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed_point_value = 0;
}

Fixed::Fixed(const Fixed& rhs)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed_point_value = rhs.getRawBits();
	//*this = rhs;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point_value = num << frac_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point_value = roundf(num * (1 << frac_bits));
}

Fixed& Fixed::operator=(const Fixed& rhs)
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
	//std::cout << "getRawBits member function called" << std::endl;
	return this->fixed_point_value;
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point_value = raw;
}

int Fixed::toInt(void) const
{
	return this->fixed_point_value >> frac_bits;
}

float Fixed::toFloat(void) const
{
	return static_cast<float>(this->fixed_point_value) / (1 << frac_bits);
}

std::ostream & operator<<(std::ostream & o, const Fixed & rhs)
{
	o << rhs.toFloat();
	return o;
}