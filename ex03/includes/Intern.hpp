#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
	// Constructors
	Intern(void);
	Intern(const Intern& other);

	// Destructor
	~Intern(void);

	// Overloaded Operator
	Intern&		operator=(const Intern& other);

	// public methods
	AForm*			makeForm(const std::string name, const std::string target);	
};

#endif