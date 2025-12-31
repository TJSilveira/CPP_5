#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Bureaucrat.hpp"

	// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(void): 
	AForm("Shrubbery Creation Form", 145, 137),
	_target("Default")
{
	std::cout << "[Form] Default constructor called. " <<
	 			this <<
				std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target):
	AForm("Shrubbery Creation Form", 145, 137),
	_target(target)
{
	std::cout << "[Form] Name constructor called. " <<
	 			this <<
			std::endl;
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other):
	AForm("Shrubbery Creation Form", 145, 137),
	_target(other.getTarget())
{
	std::cout << "[ShrubberyCreationForm] Copy constructor called. " <<
				this <<
				"Target: " << this->_target <<
				std::endl;
	return;
}

	// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	return;
}

	// Getter
const std::string	ShrubberyCreationForm::getTarget(void) const
{
	return(this->_target);
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
	std::string filename = this->getTarget() + "_shrubbery";
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