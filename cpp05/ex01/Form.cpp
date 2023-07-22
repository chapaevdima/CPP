#include "Form.hpp"

Form::Form() : name(std::string()), gradeToSign(0), gradeToExecute(0)
{
	this->isSigned = false;
}

Form::Form(const std::string& inName, int inGradeToSign) : name(inName), gradeToSign(inGradeToSign), gradeToExecute(1)
{
	this->isSigned = false;
	if (this->gradeToSign < 1)
		throw Form::GradeTooHighException();
	if (this->gradeToSign > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const std::string& inName, int inGradeToSign, int inGradeToExecute) : name(inName), gradeToSign(inGradeToSign), gradeToExecute(inGradeToExecute)
{
	this->isSigned = false;
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw Form::GradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(const Form& rhs) : name(rhs.getName()), gradeToSign(rhs.getGradeToSign()), gradeToExecute(rhs.getGradeToExecute())
{
	this->isSigned = rhs.getIsSigned();
}

Form& Form::operator=(const Form& rhs)
{
	if (this != &rhs)
		this->isSigned = rhs.getIsSigned();
	return *this;
}

Form::~Form()
{

}

std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;	
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw Form::GradeTooLowException();
	this->isSigned = true;
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

std::ostream& operator<<(std::ostream& o, const Form& form)
{
	o << "Form " << form.getName() << ": grade to sign " << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute();
	if (form.getIsSigned())
		o << ", is signed" << std::endl;
	else
		o << ", is not signed" << std::endl;
	return o;
}
