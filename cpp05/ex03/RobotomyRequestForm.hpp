#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>

class RobotomyRequestForm: public AForm
{
private:
	std::string target;

	RobotomyRequestForm();
public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& form);
	~RobotomyRequestForm();

	RobotomyRequestForm& operator=(const RobotomyRequestForm& form);

	const std::string& getTarget() const;
	void execute(const Bureaucrat& bureaucrat) const;
};

std::ostream& operator<<(std::ostream& o, const RobotomyRequestForm& form);

#endif