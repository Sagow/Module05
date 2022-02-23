#include "Intern.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
	possibleForms[0] = "presidential pardon";
	possibleForms[1] = "robotomy request";
	possibleForms[2] = "shrubbery creation";
	FormMethods[0] = &Intern::makePresidentialPardonForm;
	FormMethods[1] = &Intern::makeRobotomyRequestForm;
	FormMethods[2] = &Intern::makeShrubberyCreationForm;

}

Intern::Intern( const Intern & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

Form	*Intern::makeForm(std::string form, std::string target)
{
	int i = 0;

	while (i < (int)(possibleForms->length()) && form != possibleForms[i])
		i++;
	if (i == (int)(possibleForms->length()))
		throw (NotValidException());
	return ((this->*FormMethods[i])(target));
}

Form	*Intern::makePresidentialPardonForm(std::string target)
{
	return (new PresidentialPardonForm(target));	
}

Form	*Intern::makeRobotomyRequestForm(std::string target)
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::makeShrubberyCreationForm(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */