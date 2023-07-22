#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():AForm("presidential pardon form", 25, 5), target(std::string())
{

}

PresidentialPardonForm::PresidentialPardonForm(std::string inTarget):AForm("presidential pardon form", 25, 5), target(inTarget)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& form):AForm(form), target(form.getTarget())
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	this->target = rhs.getTarget();
	return *this;
}

const std::string& PresidentialPardonForm::getTarget() const
{
	return this->target;
}

void PresidentialPardonForm::execute(const Bureaucrat& bureaucrat) const
{
	this->checkExecute(bureaucrat);
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& form)
{
	o << form.getName() << ": grade to sign " << form.getGradeToSign();
	o << ", grade to execute " << form.getGradeToExecute() << ", target: " << form.getTarget();
	if (form.getIsSigned())
		o << ", is signed" << std::endl;
	else
		o << ", is not signed" << std::endl;
	return o;
}
