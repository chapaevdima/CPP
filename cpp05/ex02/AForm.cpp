#include "AForm.hpp"

AForm::AForm() : name(std::string()), gradeToSign(150), gradeToExecute(150)
{
	this->isSigned = false;
}

AForm::AForm(const std::string& inName, int inGradeToSign) : name(inName), gradeToSign(inGradeToSign), gradeToExecute(1)
{
	this->isSigned = false;
	if (this->gradeToSign < 1)
		throw AForm::GradeTooHighException();
	if (this->gradeToSign > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string& inName, int inGradeToSign, int inGradeToExecute) : name(inName), gradeToSign(inGradeToSign), gradeToExecute(inGradeToExecute)
{
	this->isSigned = false;
	if (this->gradeToSign < 1 || this->gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	if (this->gradeToSign > 150 || this->gradeToExecute > 150)
		throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& rhs) : name(rhs.getName()), gradeToSign(rhs.getGradeToSign()), gradeToExecute(rhs.getGradeToExecute())
{
	this->isSigned = rhs.getIsSigned();
}

AForm& AForm::operator=(const AForm& rhs)
{
	if (this != &rhs)
		this->isSigned = rhs.getIsSigned();
	return *this;
}

AForm::~AForm()
{

}

std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;	
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > this->getGradeToSign())
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

void AForm::checkExecute(const Bureaucrat& bureaucrat) const
{
	if(this->getIsSigned() == false)
		throw AForm::NotSignedException();
	if(bureaucrat.getGrade() > this->getGradeToExecute())
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return ("Grade too high");
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return ("Grade too low");
}

const char* AForm::NotSignedException::what() const throw()
{
	return ("Form is not signed");
}

std::ostream& operator<<(std::ostream& o, const AForm& form)
{
	o << "AForm " << form.getName() << ": grade to sign " << form.getGradeToSign() << ", grade to execute " << form.getGradeToExecute();
	if (form.getIsSigned())
		o << ", is signed" << std::endl;
	else
		o << ", is not signed" << std::endl;
	return o;
}
