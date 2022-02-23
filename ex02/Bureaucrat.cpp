#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("Anonymous")
{
	_grade = 150;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	std::cout << "Trying to create " << name <<", with a grade of " << grade << std::endl;
	try
	{
		setGrade(grade);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		_grade = 150;
		std::cout << "Grade set by default to " << 150 << std::endl;
	}
	
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : _name(src._name)
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
		setGrade(getGrade() - 1);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << getName() << " cannot be promoted" << std::endl;
	}
}

void		Bureaucrat::retrograde()
{
	try
	{
		setGrade(getGrade() + 1);
	}
	catch(const std::exception &e)
	{
		std::cout << e.what() << std::endl;
		std::cout << getName() << " cannot be retrograded" << std::endl;
	}
}

void		Bureaucrat::signForm(Form &form)
{
	form.beSigned(*this);
}

void		Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed form " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << "The form " << form.getName() << " couldn't be executed by " << getName() << " because ";
		std::cerr << e.what() << '\n';
	}

}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Bureaucrat::getName() const
{
	return (_name);
}

int			Bureaucrat::getGrade()
{
	return (_grade);
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	else
		_grade = grade;
}

/* ************************************************************************** */