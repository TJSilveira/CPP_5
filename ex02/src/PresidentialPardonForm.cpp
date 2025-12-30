#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Bureaucrat.hpp"

	// Constructors
PresidentialPardonForm::PresidentialPardonForm(void): AForm("Default Name", 72, 45)
{
	std::cout << "[PresidentialPardonForm] Default constructor called. " <<
	 			this <<
				std::endl;
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& name): AForm(name, 72, 45)
{
	std::cout << "[PresidentialPardonForm] Name constructor called. " <<
	 			this <<
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
	if (executor.getGrade() > this->_executionGrade)
	{
		throw AForm::GradeTooLowException();
	}
	if (this->_signed == false)
	{
		throw AForm::FormNotSignedException();
	}

	std::cout << executor.getName() << "has been pardoned by Zaphod Beeblebrox." << std::endl;
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