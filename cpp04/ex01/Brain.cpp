#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=(const Brain& rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 100; i++)
			this->ideas[i] = rhs.ideas[i];		
	}
	std::cout << "Brain assignment operator called" << std::endl;
	return *this;
}

Brain::Brain(const Brain& rhs)
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = rhs;
}