#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int main(void)
{
	std::srand(time(0));
	std::cout << "[Bureaucrat section]" << std::endl;
	Bureaucrat b1 = Bureaucrat("Tiago", 150);
	Bureaucrat b2 = Bureaucrat(2);
	Bureaucrat b3 = Bureaucrat("Ana");
	Bureaucrat b4 = Bureaucrat("Anibal");
	std::cout << &b1 << std::endl << &b2 << std::endl << &b3 << std::endl << &b4 << std::endl;

	b4 = b3;
	b4.incrementGrade();
	std::cout << &b1 << std::endl << &b2 << std::endl << &b3 << std::endl << &b4 << std::endl;
	std::cout << "\n\n";

	std::cout << "[Intern section]" << std::endl;
	Intern intern1 = Intern();

	AForm* f4 = intern1.makeForm("shrubbery creation", "Target 3");
	AForm* not_created = intern1.makeForm("Nothing", "Target 3");
	if (not_created == NULL)
		std::cout << "[Confirmation] No form was created\n";
	
	std::cout << "\n\n";

	std::cout << "[ShrubberyCreationForm section]" << std::endl;
	ShrubberyCreationForm f1 = ShrubberyCreationForm("Target 1");
	ShrubberyCreationForm f2 = ShrubberyCreationForm("Target 2");
	// ShrubberyCreationForm f4 = ShrubberyCreationForm("Target 3");

	b2.signForm(f2);
	b1.signForm(f1);
	// *f4 = f2;
	std::cout << &f1 << std::endl << &f2 << std::endl << &f4 << std::endl;
	std::cout << "\n\n";

	std::cout << "[RobotomyRequestForm section]" << std::endl;
	RobotomyRequestForm Robotomyf1 = RobotomyRequestForm("Target 1");
	RobotomyRequestForm Robotomyf2 = RobotomyRequestForm("Target 2");
	RobotomyRequestForm Robotomyf3 = RobotomyRequestForm("Target 3");

	b2.signForm(Robotomyf2);
	b1.signForm(Robotomyf1);
	Robotomyf3 = Robotomyf1;
	std::cout << &Robotomyf1 << std::endl << &Robotomyf2 << std::endl << &Robotomyf3 << std::endl;
	std::cout << "\n\n";

	std::cout << "[PresidentialPardonForm section]" << std::endl;
	PresidentialPardonForm Presidentialf1 = PresidentialPardonForm("Target 1");
	PresidentialPardonForm Presidentialf2 = PresidentialPardonForm("Target 2");
	PresidentialPardonForm Presidentialf3 = PresidentialPardonForm("Target 3");

	b2.signForm(Presidentialf2);
	b1.signForm(Presidentialf1);
	Presidentialf3 = Presidentialf1;
	std::cout << &Presidentialf1 << std::endl << &Presidentialf2 << std::endl << &Presidentialf3 << std::endl;
	std::cout << "\n\n";


	std::cout << "[Exceptions section]" << std::endl;
	try
	{
		b2.incrementGrade();
		b2.incrementGrade();
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "We are inside the FIRST catch term: " << e.what() << '\n';
	}
	try
	{
		b1.decrementGrade();
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "We are inside the SECOND catch term: " << e.what() << '\n';
	}
	try
	{
		f1.beSigned(b1);
	}
	catch(const AForm::GradeTooLowException& e)
	{
		std::cerr << "We are inside the THIRD catch term: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat b5 = Bureaucrat("Failure", 500);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the FOURTH catch term: " << e.what() << '\n';
	}

	// Shrubbery Section
	try
	{
		f2.execute(b4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the FIFTH catch term: " << e.what() << '\n';
	}
	try
	{
		b2.signForm(f2);
		f2.execute(b2);
		f2.execute(b1);
		f2.execute(b4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the SIXTH catch term: " << e.what() << '\n';
	}

	// Robotomy Section
	try
	{
		Robotomyf2.execute(b4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the SEVENTH catch term: " << e.what() << '\n';
	}
	try
	{
		b2.signForm(Robotomyf2);
		Robotomyf2.execute(b2);
		Robotomyf2.execute(b1);
		Robotomyf2.execute(b4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the EIGHTH catch term: " << e.what() << '\n';
	}

	// Presidential Section
	try
	{
		Presidentialf2.execute(b4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the NINTH catch term: " << e.what() << '\n';
	}
	try
	{
		b2.signForm(Presidentialf2);
		Presidentialf2.execute(b2);
		Presidentialf2.execute(b1);
		Presidentialf2.execute(b4);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the TENTH catch term: " << e.what() << '\n';
	}
	
	// Bureaucrat's new function
	try
	{
		b2.executeForm(f1);
		b1.executeForm(f1);
		b2.signForm(f1);
		b2.executeForm(f1);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the ELEVENTH catch term: " << e.what() << '\n';
	}

	delete f4;
}
