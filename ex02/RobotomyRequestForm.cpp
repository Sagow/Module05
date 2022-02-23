#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45)
{
	_target = "Default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 72, 45)
{
	_target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form()
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	_target = rhs._target;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "Form " << i.getName();
	o << (i.getSigned() ? " is" : " is not");
	o << " signed, it can be signed by bureaucrats level " << i.getSignGrade();
	o << " it can be executed by bureacrats level " << i.getExecGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(time(NULL));
	
	Form::execute(executor);
	std::cout << "Bzzzzzzzzzzzzzzzzzzzzzzzzbrrbrbr ";
	if (rand()%2)
		std::cout << _target << " was succesfully robotomised." << std::endl;
	else
		std::cout << _target << " couldn't be robotomised." << std::endl;

	
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */