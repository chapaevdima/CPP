#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
private:
	std::string target;

	ShrubberyCreationForm();
public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm& form);
	~ShrubberyCreationForm();

	ShrubberyCreationForm& operator=(const ShrubberyCreationForm& form);

	const std::string& getTarget() const;
	void execute(const Bureaucrat& bureaucrat) const;
};

std::ostream& operator<<(std::ostream& o, const ShrubberyCreationForm& form);

#endif