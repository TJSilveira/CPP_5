#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
public:
	// Constructors
	PresidentialPardonForm(void);
	PresidentialPardonForm(const std::string& name);

	// Destructor
	~PresidentialPardonForm(void);

	// Methods
	void	execute(Bureaucrat const & executor) const;

	// Overloaded Operator
	PresidentialPardonForm&		operator=(const PresidentialPardonForm& other);
};

#endif