#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP
#include <iostream>
#include <fstream>
#include <ctime>
#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm: public AForm
{
private:
	const std::string _target;

	// Moved here since in the subject it states that the only constructor 
	// that should be use is the one that gets target as a parameter 
	RobotomyRequestForm(void);

public:
	// Constructors
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& other);

	// Destructor
	~RobotomyRequestForm(void);

	// Getter
	const std::string	getTarget(void) const;

	// Methods
	void	execute(Bureaucrat const & executor) const;

	// Overloaded Operator
	RobotomyRequestForm&		operator=(const RobotomyRequestForm& other);
};

#endif