#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

	Form();
public:
	Form(const std::string& name, const int gradeToSign);
	Form(const std::string& name, const int gradeToSign, const int gradeToExecute);
	Form(const Form& rhs);
	~Form();

	Form& operator=(const Form& rhs);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const Form& rhs);

#endif