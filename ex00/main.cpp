#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat b1 = Bureaucrat("Tiago", 150);
	Bureaucrat b2 = Bureaucrat(2);
	Bureaucrat b3 = Bureaucrat("Ana");
	Bureaucrat b4 = Bureaucrat("Anibal");
	
	b4 = b3;
	b4.incrementGrade();
	b2.decrementGrade();
	std::cout << &b1 << std::endl << &b2 << std::endl << &b3 << std::endl << &b4 << std::endl;

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
		Bureaucrat b5 = Bureaucrat("Anibal", 200);
	}
	catch(const Bureaucrat::GradeTooLowException& e)
	{
		std::cerr << "We are inside the THIRD catch term: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat b5 = Bureaucrat("Anibal", -1);
	}
	catch(const Bureaucrat::GradeTooHighException& e)
	{
		std::cerr << "We are inside the FOURTH catch term: " << e.what() << '\n';
	}
}
