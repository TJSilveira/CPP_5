#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include "Form.hpp"

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;
public:
	// Constructors
	Bureaucrat(void);
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat(const std::string& name, const int grade);
	Bureaucrat(const std::string& name);
	Bureaucrat(const int grade);

	// Destructor
	~Bureaucrat(void);

	// Overloaded Operator
	Bureaucrat&		operator=(const Bureaucrat& other);

	// Getters
	std::string		getName(void) const;
	int				getGrade(void) const;
	
	// public methods
	void			setGrade(int grade);
	void			incrementGrade();
	void			decrementGrade();
	void			signForm(Form& form);

	// Exceptions
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	
};

// ostream Overload
std::ostream&	operator<<(std::ostream& os, const Bureaucrat* obj);

#endif