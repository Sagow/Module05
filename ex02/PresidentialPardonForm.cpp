#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5)
{
	_target = "Default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5)
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
	_target = rhs._target;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
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

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{

	Form::execute(executor);
	std::cout << _target << " got pardonned by President Zaphod Beeblebrox" << std::endl;
	
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */