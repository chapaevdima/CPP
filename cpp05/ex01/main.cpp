#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat first("first", 18);
		Form myForm("Document", 7, 2);
		for (int i = 0; i < 16; i++)
		{
			first.signForm(myForm);
			first.incrementGrade();
		}
		std::cout << myForm << std::endl;
		std::cout << first << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}