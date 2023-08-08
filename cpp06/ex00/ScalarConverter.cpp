#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter& src)
{
	*this = src;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& rhs)
{
	if (this != &rhs)
		return (*this);
	return *this;
}

ScalarConverter::~ScalarConverter()
{

}

void ScalarConverter::convert(const std::string& str)
{
	number num;
	num.c = 0;
	num.d = 0;
	num.f = 0;
	num.i = 0;
	num.is_i = false;
	num.is_f = false;
	num.is_d = false;
	num.is_c = false;

	void (*castFunc[]) (const std::string& , number&) =  {&charCast, &intCast, &doubleCast, &floatCast, &specDoubleCast, &specFloatCast};

	int type = getType(str);
	if (type == 7)
	{
		std::cout << "Wrong input" << std::endl;
		return;
	}
	castFunc[type] (str, num);
	printNumber(num);
}

int ScalarConverter::getType(const std::string& str)
{
	std::string spec_double[] = {"nan", "-inf", "+inf"};
	std::string spec_float[] = {"nanf", "-inff", "+inff"};

	if (str.size() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return 0;													//char

	for (int i = 0; i < 3; i++)
	{
		if (str.compare(spec_double[i]) == 0)
			return 4;						//special double
		if (str.compare(spec_float[i]) == 0)
			return 5;						//special float
	}

	int flag = 0;

	for (size_t i = 0; i < str.size(); i++)
	{
		switch (flag)
		{
		case 0:
			if(isdigit(str[i]))
				flag = 1;		//numeric
			else if (str[i] == '+' || str[i] == '-')
				flag = 6;
			else 
				flag = 7;
			break;
		case 1:
			if (str[i] == '.')
				flag = 8;
			else if (!isdigit(str[i]))
				flag = 7;
			break;
		case 2:
			if (str[i] == 'f')
				flag = 3;
			else if (!isdigit(str[i]))
				flag = 7;
			break;
		case 3:
			flag = 7;
			break;
		case 6:
			if (isdigit(str[i]))
				flag = 1;
			else 
				flag = 7;
			break;
		case 8:
			if (isdigit(str[i]))
				flag = 2;
			else 
				flag = 7;
			break;
		default:
			flag = 7;
			break;
		}
		if (flag == 7)
			break;
	}
	if (flag < 1 || flag > 3)
		flag = 7;
	return flag;
}

void ScalarConverter::charCast(const std::string& str, number& num)
{
	std::cout << "called char cast" << std::endl;
	num.c = str[0];
	num.is_c = true;

	num.i = static_cast<int>(num.c);
	num.is_i = true;

	num.d = static_cast<double>(num.c);
	num.is_d = true;

	num.f = static_cast<float>(num.c);
	num.is_f = true;
}

void ScalarConverter::intCast(const std::string& str, number& num)
{
	std::cout << "called int cast" << std::endl;
	std::stringstream ss;
	ss << str;
	if (!(ss >> num.i))
		return;
	num.is_i = true;

	if (num.i >= static_cast<int>(std::numeric_limits<char>::min()) && num.i <= static_cast<int>(std::numeric_limits<char>::max()))
	{
		num.c = static_cast<char>(num.i);
		num.is_c = true;
	}

	num.d = static_cast<double>(num.i);
	num.is_d = true;

	num.f = static_cast<float>(num.i);
	num.is_f = true;
}

void ScalarConverter::doubleCast(const std::string& str, number& num)
{
	std::cout << "called double cast" << std::endl;
	std::stringstream ss;
	ss << str;
	if (!(ss >> num.d))
		return;
	num.is_d = true;

	if (num.d >= static_cast<double>(std::numeric_limits<char>::min()) && num.d <= static_cast<double>(std::numeric_limits<char>::max()))
	{
		num.c = static_cast<char>(num.d);
		num.is_c = true;
	}

	if (num.d >= static_cast<double>(std::numeric_limits<int>::min()) && num.d <= static_cast<double>(std::numeric_limits<int>::max()))
	{
		num.i = static_cast<int>(num.d);
		num.is_i = true;
	}

	if (std::abs(num.d) <= static_cast<double>(std::numeric_limits<float>::max()))
	{
		num.f = static_cast<float>(num.d);
		num.is_f = true;
	}
}

void ScalarConverter::floatCast(const std::string& str, number& num)
{
	std::cout << "called float cast" << std::endl;
	std::stringstream ss;
	ss << str;
	if(!(ss >> num.f))
		return;
	num.is_f = true;

	if (num.f >= static_cast<float>(std::numeric_limits<char>::min()) && num.f <= static_cast<float>(std::numeric_limits<char>::max()))
	{
		num.c = static_cast<char>(num.f);
		num.is_c = true;
	}

	if (num.f >= static_cast<float>(std::numeric_limits<int>::min()) && num.f <= static_cast<float>(std::numeric_limits<int>::max()))
	{
		num.i = static_cast<int>(num.f);
		num.is_i = true;
	}

	num.d = static_cast<double>(num.f);
	num.is_d = true;
}

void ScalarConverter::specFloatCast(const std::string& str, number& num)
{
	std::cout << "called specfloat cast" << std::endl;
	num.f = strtof(str.c_str(), NULL);
	num.is_f = true;

	num.d = static_cast<double>(num.f);
	num.is_d = true;
}

void ScalarConverter::specDoubleCast(const std::string& str, number& num)
{
	std::cout << "called specdouble cast" << std::endl;
	num.d = strtod(str.c_str(), NULL);
	num.is_d = true;

	num.f = static_cast<float>(num.d);
	num.is_f = true;
}

void ScalarConverter::printNumber(const number& num)
{
	if(num.is_c)
	{
		if(isprint(num.c))
			std::cout << "char: " << num.c << std::endl;
		else
			std::cout << "char: non displayable" << std::endl;
	}
	else
		std::cout << "char: impossible" << std::endl;


	if(num.is_i)
		std::cout << "int: " << num.i << std::endl;
	else
		std::cout << "int: impossible" << std::endl;

	
	if(num.is_f)
		std::cout << "float: " << std::fixed << std::setprecision(1) << num.f << "f" << std::endl;
	else
		std::cout << "float: impossible" << std::endl;

	if(num.is_d)
		std::cout << "double: " << std::fixed << std::setprecision(1) << num.d << std::endl;
	else
		std::cout << "double: impossible" << std::endl;
}
