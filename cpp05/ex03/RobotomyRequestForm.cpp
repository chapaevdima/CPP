#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():AForm("robotomy request form", 72, 45), target(std::string())
{

}

RobotomyRequestForm::RobotomyRequestForm(std::string inTarget):AForm("robotomy request form", 72, 45), target(inTarget)
{

}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& form):AForm(form), target(form.getTarget())
{

}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	this->target = rhs.getTarget();
	return *this;
}

const std::string& RobotomyRequestForm::getTarget() const
{
	return this->target;
}

void RobotomyRequestForm::execute(const Bureaucrat& bureaucrat) const
{
	this->checkExecute(bureaucrat);
	int random = std::rand() % 2;
	std::cout << "Bzzzz Wrrrrr" << std::endl;
	if (random)
		std::cout << this->getTarget() << " has been robotomized" << std::endl;
	else
		std::cout << this->getTarget() << " has not been robotomized" << std::endl;
}

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& form)
{
	o << form.getName() << ": grade to sign " << form.getGradeToSign();
	o << ", grade to execute " << form.getGradeToExecute() << ", target: " << form.getTarget();
	if (form.getIsSigned())
		o << ", is signed" << std::endl;
	else
		o << ", is not signed" << std::endl;
	return o;
}
