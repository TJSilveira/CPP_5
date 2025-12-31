#include <iostream>
#include <ostream>
#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

AForm::AForm(void): _name("Defaultus Formus"), _signed(false), _signingGrade(1), _executionGrade(1)
{
	std::cout << "[Form] Default constructor called. " <<
	 			this <<
				std::endl;
	return;
}

AForm::AForm(const AForm& other): _name(other.getName() + "_copy"), _signed(other.getSigned()), _signingGrade(other.getSigningGrade()), _executionGrade(other.getExecutionGrade())
{
	std::cout << "[Form] Copy constructor called. " <<
	 			this <<
				std::endl;
	return;
}

AForm::AForm(const std::string& name, const int signing_grade, const int execution_grade): _name(name), _signed(false), _signingGrade(signing_grade), _executionGrade(execution_grade)
{
	std::cout << "[Form] Parameterized constructor called. " <<
	 			this <<
				std::endl;
	if (signing_grade > 150 || execution_grade > 150)
		throw AForm::GradeTooLowException();
	else if (signing_grade < 1 || execution_grade < 1)
		throw AForm::GradeTooHighException();
	return;
}

AForm::AForm(const std::string& name): _name(name), _signed(false), _signingGrade(1), _executionGrade(1)
{
	std::cout << "[Form] Name constructor called. " <<
	 			this <<
			std::endl;
	return;
}

AForm& AForm::operator=(const AForm& other)
{
	if(this != &other)
		this->_signed = other.getSigned();

	std::cout << "[Form] Copy assignment operator called. " <<
	 			this <<
			std::endl;

	return *this;
}

AForm::~AForm()
{
	std::cout << "[Form] Destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const AForm* obj)
{
	os << 	"Name: " << obj->getName() << "; " <<
			"Signed: " << obj->getSigned() << "; " <<
			"SigningGrade: " << obj->getSigningGrade() << "; " <<
			"ExecutionGrade: " << obj->getExecutionGrade() << ";";
	return(os);
}

std::string AForm::getName(void) const
{
	return (this->_name);
}

bool		AForm::getSigned(void) const
{
	return (this->_signed);
}

int	AForm::getSigningGrade(void) const
{
	return (this->_signingGrade);
}

int	AForm::getExecutionGrade(void) const
{
	return (this->_executionGrade);
}

void	AForm::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() > this->_signingGrade)
	{
		throw AForm::GradeTooLowException();
	}
	this->_signed = true;
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return ("Form not signed");
}
