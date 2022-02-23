#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : _name("Default form"), _signGrade(1), _execGrade(1)
{
	_signed = false;
}

Form::Form( const Form & src ) : _name(src._name), _signGrade(src._signGrade), _execGrade(src._execGrade)
{
	*this = src;
}

Form::Form(std::string name, int sign, int exec) : _name(name), _signGrade(sign), _execGrade(exec)
{
	_signed = false;
	if (sign < 1 || exec < 1)
		throw (GradeTooHighException());
	else if (sign > 150 || exec > 150)
		throw (GradeTooLowException());
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	_signed = rhs._signed;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form " << i.getName();
	o << (i.getSigned() ? " is" : " is not");
	o << " signed, it can be signed by bureaucrats level " << i.getSignGrade() << (i.getSignGrade() > 1 ? " and up," : ",");
	o << " it can be executed by bureacrats level " << i.getExecGrade() << (i.getExecGrade() > 1 ? " and up." : ".");
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void		Form::beSigned(Bureaucrat &bureaucrat)
{
	try
	{
		setSigned(bureaucrat.getGrade());
		std::cout << bureaucrat.getName() << " signed " << getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << bureaucrat.getName() << " couldn't sign " << getName() << " because ";
		std::cerr << e.what() << '\n';
	}
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string	Form::getName() const
{
	return (_name);
}

bool		Form::getSigned() const
{
	return (_signed);
}

void		Form::setSigned(int grade)
{
	if (_signed)
		throw (AlreadySignedException());
	else if (grade > getSignGrade())
		throw (GradeTooLowException());
	else _signed = true;
}

int			Form::getSignGrade() const
{
	return (_signGrade);
}

int			Form::getExecGrade() const
{
	return (_execGrade);
}

/* ************************************************************************** */