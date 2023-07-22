#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat first = Bureaucrat("first", 1);
		for (int i = 0; i < 200; i++)
		{
			first.decrementGrade();
			std::cout << i << std::endl;
		}
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}