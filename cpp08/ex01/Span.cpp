#include "Span.hpp"

Span::Span()
{
	n = 0;
}

Span::Span(unsigned int n)
{
	this->n = n;
}

Span::~Span()
{

}

Span& Span::operator=(const Span& rhs)
{
	this->n = rhs.n;
	this->vec = rhs.vec;
	return *this;
}

Span::Span(const Span& src)
{
	*this = src;
}

void Span::addNumber(int num)
{
	if(vec.size() < n)
		vec.push_back(num);
	else
		throw OutOfBoundsException();
}

void Span::addRange(std::vector<int> src)
{
	if(vec.size() + src.size() <= n)
		vec.insert(vec.end(), src.begin(), src.end());
	else
		throw OutOfBoundsException();
}

void Span::addRange(std::vector<int>::iterator it1, std::vector<int>::iterator it2)
{
	std::vector<int> src(it1, it2);
	if(vec.size() + src.size() <= n)
		vec.insert(vec.end(), src.begin(), src.end());
	else
		throw OutOfBoundsException();
}

unsigned int Span::shortestSpan()
{
	if(vec.size() < 2)
		throw NotEnoughElementsException();
	std::vector<int> tmp = vec;
	std::sort(tmp.begin(), tmp.end());
	unsigned int res = vec[1] - vec[0];
	for (size_t i = 0; i < tmp.size() - 1; i++)
		res = std::min(res, static_cast<unsigned int>(tmp[i + 1] - tmp[i]));
	return res;
}

unsigned int Span::longestSpan()
{
	if(vec.size() < 2)
		throw NotEnoughElementsException();
	unsigned int res = static_cast<unsigned int>(*(std::max_element(vec.begin(), vec.end())) - *(std::min_element(vec.begin(), vec.end())));
	return res;
}

const char *Span::OutOfBoundsException::what() const throw()
{
	return "Span:exception: index out of bounds";
}

const char *Span::NotEnoughElementsException::what() const throw()
{
	return "Span:exception: not enough elements";
}
