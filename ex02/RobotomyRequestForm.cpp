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
	setName(((RobotomyRequestForm)rhs).getName());
	setSigned(((RobotomyRequestForm)rhs).getSigned());
	setSignGrade(((RobotomyRequestForm)rhs).getSignGrade());
	setExecGrade(((RobotomyRequestForm)rhs).getExecGrade());

	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	RobotomyRequestForm::execute(Bureaucrat const & executor)
{
	srand(NULL);
	try
	{
		execution(((Bureaucrat)executor).getGrade());
		std::cout << "Bzzzzzzzzzzzzzzzzzzzzzzzzbrrbrbr ";
		if (rand()%2)
			std::cout << _target << " was succesfully robotomised." << std::endl;
		else
			std::cout << _target << " couldn't be robotomised." << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cout << "The form " << getName() << "couldn't be executed by " << ((Bureaucrat)executor).getName() << " because ";
		std::cerr << e.what() << '\n';
	}
	
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */