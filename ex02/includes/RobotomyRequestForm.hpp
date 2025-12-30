#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <fstream>
#include <ctime>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
public:
	// Constructors
	RobotomyRequestForm(void);
	RobotomyRequestForm(const std::string& name);

	// Destructor
	~RobotomyRequestForm(void);

	// Methods
	void	execute(Bureaucrat const & executor) const;

	// Overloaded Operator
	RobotomyRequestForm&		operator=(const RobotomyRequestForm& other);
};

#endif