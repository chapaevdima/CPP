#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	AForm	*form = 0;

	try
	{
		Bureaucrat	bureaucrat = Bureaucrat("bureaucrat", 5);
		Intern intern = Intern();

		

		form = intern.makeForm("shrubbery creation", "target");

		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);

		std::cout << std::endl;

		delete form;

		form = intern.makeForm("robotomy request","target");
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;

		for (int i = 0; i < 13; i++)
			bureaucrat.executeForm(*form);

		std::cout << std::endl;

		delete form;

		form = intern.makeForm("presidential pardon", "target");
		bureaucrat.signForm(*form);
		std::cout << *form << std::endl;
		bureaucrat.executeForm(*form);
		delete form;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}