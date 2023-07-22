#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
private:
	const std::string	name;
	int					grade;
	Bureaucrat();

public:
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat (const Bureaucrat& rhs);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat& rhs);

	std::string getName() const;
	int getGrade() const;

	void incrementGrade();
	void decrementGrade();

	void signForm(Form& form);

	class GradeTooHighException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);

#endif