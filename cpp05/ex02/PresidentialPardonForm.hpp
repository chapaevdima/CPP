#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	std::string target;

	PresidentialPardonForm();
public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& form);
	~PresidentialPardonForm();

	PresidentialPardonForm& operator=(const PresidentialPardonForm& form);

	const std::string& getTarget() const;
	void execute(const Bureaucrat& bureaucrat) const;
};

std::ostream& operator<<(std::ostream& o, const PresidentialPardonForm& form);

#endif