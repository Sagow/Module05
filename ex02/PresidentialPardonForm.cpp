#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 1)
{
	_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 1)
{
	_target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : Form()
{
	*this = src;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	setName(((PresidentialPardonForm)rhs).getName());
	setSigned(((PresidentialPardonForm)rhs).getSigned());
	setSignGrade(((PresidentialPardonForm)rhs).getSignGrade());
	setExecGrade(((PresidentialPardonForm)rhs).getExecGrade());

	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	PresidentialPardonForm::execute(Bureaucrat const & executor)
{
	try
	{
		execution(((Bureaucrat)executor).getGrade());
		std::cout << _target << " got pardonned by President Zaphod Beeblebrox" << std::endl;
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