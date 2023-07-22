#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	AForm *makeShrubbery(const std::string& target) const;
	AForm *makeRobotomy(const std::string& target) const;
	AForm *makePardon(const std::string& target) const;
public:
	Intern();
	Intern(const Intern& intern);
	~Intern();
	Intern& operator=(const Intern& rhs);

	AForm *makeForm(const std::string& name, const std::string& target) const;

	class BadFormName: public std::exception
	{
		const char *what() const throw();
	};
};

#endif