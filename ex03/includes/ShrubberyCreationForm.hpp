#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
private:
	const std::string _target;

	// Moved here since in the subject it states that the only constructor 
	// that should be use is the one that gets target as a parameter 
	ShrubberyCreationForm(void);

public:
	// Constructors
	ShrubberyCreationForm(const std::string& name);
	ShrubberyCreationForm(const ShrubberyCreationForm& other);

	// Destructor
	~ShrubberyCreationForm(void);

	// Getter
	const std::string	getTarget(void) const;

	// Methods
	void	doAction(Bureaucrat const & executor) const;

	// Overloaded Operator
	ShrubberyCreationForm&		operator=(const ShrubberyCreationForm& other);
};

#endif