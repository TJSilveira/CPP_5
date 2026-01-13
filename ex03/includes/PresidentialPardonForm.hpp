#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP
#include <iostream>
#include <fstream>
#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm: public AForm
{
private:
	const std::string _target;

	// Moved here since in the subject it states that the only constructor 
	// that should be use is the one that gets target as a parameter 
	PresidentialPardonForm(void);
public:
	// Constructors
	PresidentialPardonForm(const std::string& target);
	PresidentialPardonForm(const PresidentialPardonForm& other);

	// Destructor
	~PresidentialPardonForm(void);

	// Getter
	const std::string	getTarget(void) const;

	// Methods
	void	doAction(Bureaucrat const & executor) const;

	// Overloaded Operator
	PresidentialPardonForm&		operator=(const PresidentialPardonForm& other);
};

#endif