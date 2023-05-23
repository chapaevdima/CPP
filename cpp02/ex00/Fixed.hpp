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
	Fixed(Fixed &rhs);
	Fixed& operator=(Fixed &rhs);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};


#endif