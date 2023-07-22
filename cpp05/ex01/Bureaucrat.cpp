#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{

}

Bureaucrat::Bureaucrat(const std::string& in_name, int grade) : name(in_name)
{
	this->grade = grade;
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat& rhs) : name(rhs.getName())
{
	this->grade = rhs.getGrade();
}

Bureaucrat::~Bureaucrat()
{

}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
		this->grade = rhs.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
	
}

const char* Bureaucrat::GradeTooHighException:: what() const throw()
{
	return ("Grade too high");
}

const char* Bureaucrat::GradeTooLowException:: what() const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs)
{
	o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << std::endl;
	return o;
}