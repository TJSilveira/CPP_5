#ifndef AFORM_HPP
#define AFORM_HPP
#include <iostream>

class Bureaucrat;

class AForm
{
protected:
	const std::string	_name;
	bool				_signed;
	const int			_signingGrade;
	const int			_executionGrade;
public:
	// Constructors
	AForm(void);
	AForm(const AForm& other);
	AForm(const std::string& name, const int signing_grade, const int execution_grade);
	AForm(const std::string& name);

	// Destructor
	~AForm(void);

	// Overloaded Operator
	AForm&		operator=(const AForm& other);

	// Getters
	std::string		getName(void) const;
	bool			getSigned(void) const;
	int				getSigningGrade(void) const;
	int				getExecutionGrade(void) const;

	// Methods
	void			beSigned(const Bureaucrat& signer);
	virtual	void	execute(Bureaucrat const & executor) const =0;

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
	
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// ostream Overload
std::ostream&	operator<<(std::ostream& os, const AForm* obj);

#endif