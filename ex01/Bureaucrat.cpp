#include <iostream>
#include <ostream>
#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("Defaultus Maximus"), _grade(150)
{
	std::cout << "[Bureaucrat] Default constructor called. " <<
	 			"Name assigned: " << this->_name << "; " <<
				"Grade assigned: " << this->_grade << ";" <<
				std::endl;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other.getName() + "_copy"), _grade(other.getGrade())
{
	std::cout << "[Bureaucrat] Copy constructor called. " <<
	 			"Name assigned: " << this->_name << "; " <<
				"Grade assigned: " << this->_grade << ";" <<
				std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string& name, const int grade): _name(name)
{
	this->setGrade(grade);
	std::cout << "[Bureaucrat] Parameterized constructor called. " <<
			"Name assigned: " << this->_name << "; " <<
			"Grade assigned: " << this->_grade << ";" <<
			std::endl;
	return;
}

Bureaucrat::Bureaucrat(const std::string& name): _name(name), _grade(150)
{
	std::cout << "[Bureaucrat] Name constructor called. " <<
			"Name assigned: " << this->_name << "; " <<
			"Grade assigned: " << this->_grade << ";" <<
			std::endl;
	return;
}

Bureaucrat::Bureaucrat(const int grade): _name("Defaultus Maximus")
{
	this->setGrade(grade);
	std::cout << "[Bureaucrat] Grade constructor called. " <<
			"Name assigned: " << this->_name << "; " <<
			"Grade assigned: " << this->_grade << ";" <<
			std::endl;
	return;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if(this != &other)
		this->_grade = other.getGrade();

	std::cout << "[Bureaucrat] Copy assignment operator called. " <<
		"Name assigned: " << this->_name << "; " <<
		"Grade assigned: " << this->_grade << ";" <<
		std::endl;

	return *this;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "[Bureaucrat] Destructor called" << std::endl;
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat* obj)
{
	os << obj->getName() << ", bureaucrat grade " << obj->getGrade();
	return(os);
}

int	Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
}


std::string Bureaucrat::getName(void) const
{
	return (this->_name);
}

void		Bureaucrat::incrementGrade(void)
{
	this->setGrade(this->_grade - 1); 
}

void		Bureaucrat::decrementGrade(void)
{
	this->setGrade(this->_grade + 1);
}

void		Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << "." <<std::endl;
	}	
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
}
