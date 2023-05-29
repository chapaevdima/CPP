#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int fixed_point_value;
	static const int frac_bits = 8;
	
public:
	Fixed();
	~Fixed();
	Fixed(const Fixed &rhs);
	Fixed(const int num);
	Fixed(const float num);
	Fixed& operator=(const Fixed &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);

	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream & operator<<(std::ostream & o, const Fixed & rhs);

#endif