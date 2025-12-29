#include "Bureaucrat.hpp"

int main(void)
{
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

	std::cout << "[Form section]" << std::endl;
	Form f1 = Form();
	Form f2 = Form("F2");
	Form f3 = Form("F3", 10, 20);
	Form f4 = Form("Fz");

	b2.signForm(f3);
	b1.signForm(f1);
	f4 = f3;
	std::cout << &f1 << std::endl << &f2 << std::endl << &f3 << std::endl << &f4 << std::endl;
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
	catch(const Form::GradeTooLowException& e)
	{
		std::cerr << "We are inside the THIRD catch term: " << e.what() << '\n';
	}
	try
	{
		Form f5 = Form("Failure", -20, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the FOURTH catch term: " << e.what() << '\n';
	}
	try
	{
		Bureaucrat b5 = Bureaucrat("Failure", 500);
	}
	catch(const std::exception& e)
	{
		std::cerr << "We are inside the FIFTH catch term: " << e.what() << '\n';
	}
}
