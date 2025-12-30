#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm: public AForm
{
public:
	// Constructors
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string& name);

	// Destructor
	~ShrubberyCreationForm(void);

	// Methods
	void	execute(Bureaucrat const & executor) const;

	// Overloaded Operator
	ShrubberyCreationForm&		operator=(const ShrubberyCreationForm& other);
};

#endif