#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat()
{
	_name = "Anonymous";
	_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
{
	_name = name;
	try
	{
		if (_grade > 0 && _grade <= 150)
			_grade = grade;
		else if (_grade < 1)
			throw (GradeTooHighException);
		else
			throw (GradeTooLowException);

	}
	catch(const std::exception& e)
	{
		if (e)
	}
	
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & rhs )
{
	_name = rhs._name;
	_grade = rhs._grade;

	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	std::cout << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */