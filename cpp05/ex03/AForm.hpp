#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

	AForm();
public:
	AForm(const std::string& name, const int gradeToSign);
	AForm(const std::string& name, const int gradeToSign, const int gradeToExecute);
	AForm(const AForm& rhs);
	virtual ~AForm();

	AForm& operator=(const AForm& rhs);

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	virtual void execute(const Bureaucrat& bureaucrat) const = 0;
	void checkExecute(const Bureaucrat& bureaucrat) const;

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

	class NotSignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& o, const AForm& rhs);

#endif