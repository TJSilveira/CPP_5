#include <iostream>
#include <ostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("Defaultus Formus"), _signed(false), _signingGrade(1), _executionGrade(1)
{
	std::cout << "[Form] Default constructor called. " <<
	 			this <<
				std::endl;
	return;
}

Form::Form(const Form& other): _name(other.getName() + "_copy"), _signed(other.getSigned()), _signingGrade(other.getSigningGrade()), _executionGrade(other.getExecutionGrade())
{
	std::cout << "[Form] Copy constructor called. " <<
	 			this <<
				std::endl;
	return;
}

Form::Form(const std::string& name, const int signing_grade, const int execution_grade): _name(name), _signed(false), _signingGrade(signing_grade), _executionGrade(execution_grade)
{
	if (signing_grade > 150 || execution_grade > 150)
		throw Form::GradeTooLowException();
	else if (signing_grade < 1 || execution_grade < 1)
		throw Form::GradeTooHighException();
	std::cout << "[Form] Parameterized constructor called. " <<
	 			this <<
				std::endl;
	return;
}

Form::Form(const std::string& name): _name(name), _signed(false), _signingGrade(1), _executionGrade(1)
{
	std::cout << "[Form] Name constructor called. " <<
	 			this <<
			std::endl;
	return;
}

Form& Form::operator=(const Form& other)
{
	if(this != &other)
		this->_signed = other.getSigned();

	std::cout << "[Form] Copy assignment operator called. " <<
	 			this <<
			std::endl;

	return *this;
}

Form::~Form()
{
	std::cout << "[Form] Destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Form* obj)
{
	os << 	"Name: " << obj->getName() << "; " <<
			"Signed: " << obj->getSigned() << "; " <<
			"SigningGrade: " << obj->getSigningGrade() << "; " <<
			"ExecutionGrade: " << obj->getExecutionGrade() << ";";
	return(os);
}

std::string Form::getName(void) const
{
	return (this->_name);
}

bool		Form::getSigned(void) const
{
	return (this->_signed);
}

int	Form::getSigningGrade(void) const
{
	return (this->_signingGrade);
}

int	Form::getExecutionGrade(void) const
{
	return (this->_executionGrade);
}

void	Form::beSigned(const Bureaucrat& signer)
{
	if (signer.getGrade() > this->_signingGrade)
	{
		throw Form::GradeTooLowException();
	}
	std::cout << "Bureaucrat "<< signer.getName() << " signed the form "<< this->getName() << std::endl;
	this->_signed = true;
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}
