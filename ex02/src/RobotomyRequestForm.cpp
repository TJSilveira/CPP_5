#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/Bureaucrat.hpp"

	// Constructors
RobotomyRequestForm::RobotomyRequestForm(void): 
	AForm("Robotomy Request Form", 72, 45),
	_target("Default")
{
	std::cout << "[RobotomyRequestForm] Default constructor called. " <<
	 			this <<
				std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target):
	AForm("Robotomy Request Form", 72, 45),
	_target(target)
{
	std::cout << "[RobotomyRequestForm] Name constructor called. " <<
	 			this <<
			std::endl;
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):
	AForm("Robotomy Request Form", 72, 45),
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
void	RobotomyRequestForm::doAction(Bureaucrat const & executor) const
{
    int randomNum = std::rand();
	std::cout << "*drill noises* BBBBBBBBBBBBBBRRRRRRRRRRRRRRRRRRHHHHHHHHHHHHHHHHH *drill noises*" << std::endl;
	if (randomNum % 2)
		std::cout << this->getTarget() << " has been robotomized successfully!" << std::endl;
	else
		std::cout << "Robotomized Failed" << std::endl;
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
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