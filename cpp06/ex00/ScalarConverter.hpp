#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <cstdlib>
# include <limits>
# include <sstream>
# include <cmath>
# include <iomanip>

typedef struct s_number
{
	int		i;
	char	c;
	float	f;
	double	d;

	bool	is_i;
	bool	is_c;
	bool	is_f;
	bool	is_d;
} number;


class ScalarConverter
{
private:	

	ScalarConverter();
	ScalarConverter(const ScalarConverter& src);
	~ScalarConverter();
	ScalarConverter& operator=(const ScalarConverter& rhs);

	static int getType(const std::string& str);

	static void intCast(const std::string& str, number& nb);
	static void charCast(const std::string& str, number& nb);
	static void floatCast(const std::string& str, number& nb);
	static void doubleCast(const std::string& str, number& nb);
	static void specFloatCast(const std::string& str, number& nb);
	static void specDoubleCast(const std::string& str, number& nb);

	static void printNumber (const number& nb);
public: 

	static void convert(const std::string& str);

};

#endif