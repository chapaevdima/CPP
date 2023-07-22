#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	AForm	*form = 0;

	try
	{
		Bureaucrat	bureaucrat = Bureaucrat("bureaucrat", 5);

		

		form = new ShrubberyCreationForm("target");

		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);

		std::cout << std::endl;

		delete form;

		form = new RobotomyRequestForm("target");
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;

		for (int i = 0; i < 13; i++)
			bureaucrat.executeForm(*form);

		std::cout << std::endl;

		delete form;

		form = new PresidentialPardonForm("target");
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	delete form;
}