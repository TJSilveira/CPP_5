#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

	// Constructors
RobotomyRequestForm::RobotomyRequestForm(void): 
	AForm("Robotomy Request", 72, 45),
	_target("Default")
{
	std::cout << "[RobotomyRequestForm] Default constructor called. " <<
	 			this <<
				std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("Robotomy Request", 72, 45),
	_target(target)
{
	std::cout << "[RobotomyRequestForm] Name constructor called. " <<
	 			this <<
			std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm("Robotomy Request", 72, 45),
	_target(other.getTarget())
{
	std::cout << "[RobotomyRequestForm] Copy constructor called. " <<
				this <<
				"Target: " << this->_target <<
				std::endl;
	return;
}

	// Destructor
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	return;
}

	// Getter
const std::string	RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
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
		std::cout << this->getTarget() << "has been robotomized successfully" << std::endl;
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