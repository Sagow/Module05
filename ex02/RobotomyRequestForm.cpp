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
	setName(rhs.getName());
	setSigned(rhs.getSigned());
	setSignGrade(rhs.getSignGrade());
	setExecGrade(rhs.getExecGrade());

	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	srand(time(NULL));
	
	execution(((Bureaucrat)executor).getGrade());
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