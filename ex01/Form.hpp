#ifndef FORM_HPP
#define FORM_HPP
#include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string	_name;
	bool				_signed;
	const int			_signingGrade;
	const int			_executionGrade;
public:
	// Constructors
	Form(void);
	Form(const Form& other);
	Form(const std::string& name, const int signing_grade, const int execution_grade);
	Form(const std::string& name);

	// Destructor
	~Form(void);

	// Overloaded Operator
	Form&		operator=(const Form& other);

	// Getters
	std::string		getName(void) const;
	bool			getSigned(void) const;
	int				getSigningGrade(void) const;
	int				getExecutionGrade(void) const;

	// Methods
	void			beSigned(const Bureaucrat& signer);

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
std::ostream&	operator<<(std::ostream& os, const Form* obj);

#endif