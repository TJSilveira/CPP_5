#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

	// Constructors
PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("Presidential Pardon", 25, 5),
	_target("Default Presidential Pardon")
{
	std::cout << "[PresidentialPardonForm] Default constructor called. " <<
	 			this <<
				"Target: " << this->_target <<
				std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target):
	AForm("Presidential Pardon", 25, 5),
	_target(target)
{
	std::cout << "[PresidentialPardonForm] Name constructor called. " <<
	 			this <<
				"Target: " << this->_target <<
			std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other):
	AForm("Presidential Pardon", 25, 5),
	_target(other.getTarget())
{
	std::cout << "[PresidentialPardonForm] Copy constructor called. " <<
				this <<
				"Target: " << this->_target <<
				std::endl;
	return;
}


	// Destructor
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	return;
}

	// Methods
void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getExecutionGrade())
	{
		throw AForm::GradeTooLowException();
	}
	if (this->_signed == false)
	{
		throw AForm::FormNotSignedException();
	}

	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}

const std::string	PresidentialPardonForm::getTarget(void) const
{
	return(this->_target);
}

	// Overloaded Operator
PresidentialPardonForm&		PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
	if(this != &other)
		this->_signed = other.getSigned();

	std::cout << "[PresidentialPardonForm] Copy assignment operator called. " <<
	 			this <<
			std::endl;

	return *this;
}