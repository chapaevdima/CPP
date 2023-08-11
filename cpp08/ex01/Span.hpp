#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>

class Span
{
private:
	std::vector<int> vec;
	unsigned int n;

	Span();

	class OutOfBoundsException: public std::exception
	{
		virtual const char *what() const throw();
	};

	class NotEnoughElementsException: public std::exception
	{
		virtual const char* what() const throw();
	};

public:
	Span(unsigned int num);
	~Span();
	Span(const Span& src);
	Span& operator=(const Span& rhs);

	void addNumber(int num);
	void addRange(std::vector<int> src);
	unsigned int shortestSpan();
	unsigned int longestSpan();
};

#endif