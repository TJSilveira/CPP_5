#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

	// Constructors
RobotomyRequestForm::RobotomyRequestForm(void): AForm("Default Name", 72, 45)
{
	std::cout << "[RobotomyRequestForm] Default constructor called. " <<
	 			this <<
				std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& name): AForm(name, 72, 45)
{
	std::cout << "[RobotomyRequestForm] Name constructor called. " <<
	 			this <<
			std::endl;
	return;
}

	// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

	// Methods
void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_executionGrade)
	{
		throw AForm::GradeTooLowException();
	}
	if (this->_signed == false)
	{
		throw AForm::FormNotSignedException();
	}

	std::cout << "*drill noises* BBBBBBBBBBBBBBRRRRRRRRRRRRRRRRRRHHHHHHHHHHHHHHHHH *drill noises*" << std::endl;
	if (time(NULL) % 2)
		std::cout << executor.getName() << "has been robotomized successfully" << std::endl;
	else
		std::cout << "Robotomized Failed" << std::endl;
}

	// Overloaded Operator
RobotomyRequestForm&		RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
	if(this != &other)
		this->_signed = other.getSigned();

	std::cout << "[RobotomyRequestForm] Copy assignment operator called. " <<
	 			this <<
			std::endl;

	return *this;
}