#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

	// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Default Name", 145, 137)
{
	std::cout << "[Form] Default constructor called. " <<
	 			this <<
				std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name): AForm(name, 145, 137)
{
	std::cout << "[Form] Name constructor called. " <<
	 			this <<
			std::endl;
	return;
}

	// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

	// Methods
void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->_executionGrade)
	{
		throw AForm::GradeTooLowException();
	}
	if (this->_signed == false)
	{
		throw AForm::FormNotSignedException();
	}
	std::string filename = this->getName() + "_shrubbery";
	std::ofstream myfile(filename.c_str());
	std::string tree = 
	"               &&& &&  & &&\n          && &/ /&/|& ()|/ @, &&\n          &/ /(/&/&||/& /_/)_&/_&\n       &() &/ /&|()|/&/  '%\" & ()\n      &_/_&&_/ |& |&&/&__%_/_& &&\n    &&   && & &| &| /& & % ()& /&&\n     ()&_---()&/&/|&&-&&--%---()~\n         &&     /|||\n                |||\n                |||\n                |||\n          , -=-~  .-^- _\n";
	myfile << tree;
	myfile.close();
	std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

	// Overloaded Operator
ShrubberyCreationForm&		ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
	if(this != &other)
		this->_signed = other.getSigned();

	std::cout << "[ShrubberyCreationForm] Copy assignment operator called. " <<
	 			this <<
			std::endl;

	return *this;
}