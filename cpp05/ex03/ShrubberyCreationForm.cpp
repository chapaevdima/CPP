#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm():AForm("shrubbery creation form", 145, 137), target(std::string())
{

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string inTarget):AForm("shrubbery creation form", 145, 137), target(inTarget)
{

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form):AForm(form), target(form.getTarget())
{

}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	this->target = rhs.getTarget();
	return *this;
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return this->target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& bureaucrat) const
{
	this->checkExecute(bureaucrat);
	std::string fileName = target + "_shrubbery";
	std::ofstream file(fileName.c_str());
	file.exceptions(file.badbit);
	file << "               ,@@@@@@@,							" << std::endl;
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.				" << std::endl;
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o				" << std::endl;
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'			" << std::endl;
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'			" << std::endl;
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'			" << std::endl;
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'				" << std::endl;
	file << "       |o|        | |         | |					" << std::endl;
	file << "       |.|        | |         | |					" << std::endl;
	file << "    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_	" << std::endl;
}

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& form)
{
	o << form.getName() << ": grade to sign " << form.getGradeToSign();
	o << ", grade to execute " << form.getGradeToExecute() << ", target: " << form.getTarget();
	if (form.getIsSigned())
		o << ", is signed" << std::endl;
	else
		o << ", is not signed" << std::endl;
	return o;
}
