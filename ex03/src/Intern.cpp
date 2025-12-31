#include <iostream>
#include <ostream>
#include "../includes/Intern.hpp"

Intern::Intern(void)
{
	std::cout << "[Intern] Default constructor called. " <<
				std::endl;
	return;
}

Intern::Intern(const Intern& other)
{
	std::cout << "[Intern] Copy constructor called. " <<
				std::endl;
	*this = other;
	return;
}

Intern& Intern::operator=(const Intern& other)
{
	std::cout << "[Intern] Copy assignment operator called. " <<
		std::endl;
	if(this == &other)
		return *this;
	return *this;
}

Intern::~Intern()
{
	std::cout << "[Intern] Destructor called" << std::endl;
}

static AForm*	makePresidential(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm*	makeRobotomy(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm*	makeShrubbery(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::makeForm(const std::string name, const std::string target)
{
	AForm *(*all_forms[])(const std::string target) = {&makePresidential, &makeRobotomy, &makeShrubbery};
	std::string all_names[] = {"presidential pardon", "robotomy request", "shrubbery creation"};

	for (size_t i = 0; i < all_names->length(); i++)
	{
		if (name == all_names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (all_forms[i](target));
		}
	}
	std::cout << "\033[33mIntern can not create a form called " << name << "\033[0m" << std::endl;
	return (NULL);
}


