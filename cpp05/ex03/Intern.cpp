#include "Intern.hpp"

Intern::Intern()
{

}

Intern::Intern(const Intern& intern)
{
	(void)intern;
}

Intern::~Intern()
{

}

Intern& Intern::operator=(const Intern& rhs)
{
	(void)rhs;
	return *this;
}

AForm *Intern::makeShrubbery(const std::string& target) const
{
	AForm *form = new ShrubberyCreationForm(target);
	return form;
}

AForm *Intern::makeRobotomy(const std::string& target) const
{
	AForm *form = new RobotomyRequestForm(target);
	return form;
}

AForm *Intern::makePardon(const std::string& target) const
{
	AForm *form = new PresidentialPardonForm(target);
	return form;
}

AForm *Intern::makeForm(const std::string& name, const std::string& target) const
{
	std::string names[] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm *(Intern::*make[]) (const std::string&) const = {&Intern::makeShrubbery, &Intern::makeRobotomy, &Intern::makePardon};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << " form" << std::endl;
			return (this->*make[i])(target);
		}
	}
	std::cout << "Intern cann't create " << name << " form" << std::endl;
	throw BadFormName();
	return NULL; 
}

const char *Intern::BadFormName::what() const throw()
{
	return ("incorrect form name");
}
