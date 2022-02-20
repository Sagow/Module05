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
	std::cout << "Trying to create " << name <<", with a grade of " << grade << std::endl;
	_name = name;
	try
	{
		if (_grade < 1)
			throw (GradeTooHighException());
		else if (_grade > 150)
			throw (GradeTooLowException());
		else
			_grade = grade;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
	
}

Bureaucrat::Bureaucrat( const Bureaucrat & src )
{
	*this = src;
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
	std::cout << ((Bureaucrat)i).getName() << ", bureaucrat grade " << ((Bureaucrat)i).getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Bureaucrat::promote()
{
	try
	{
		if (getGrade() == 1)
			throw (GradeTooHighException());
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	_grade--;
}

void		Bureaucrat::retrograde()
{
	try
	{
		if (getGrade() == 150)
			throw (GradeTooLowException());
	}
	catch(const std::exception &e)
	{
		std::cout << e.what();
	}
	_grade++;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName()
{
	return (_name);
}

int			Bureaucrat::getGrade()
{
	return (_grade);
}

/* ************************************************************************** */