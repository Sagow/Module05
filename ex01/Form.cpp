#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form()
{
	_name = "Default form";
	_signed = false;
	_signGrade = 1;
	_execGrade = 1;
}

Form::Form( const Form & src )
{
	*this = src;
}

Form::Form(std::string name, int sign, int exec)
{
	_name = name;
	_signed = false;
	try
	{
		setSignGrade(sign);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		_signGrade = 1;
		std::cout << "Signing grade set by default to 1" << std::endl;
	}
	try
	{
		setExecGrade(exec);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		_execGrade = 1;
		std::cout << "Execution grade set by default to 1" << std::endl;
	}
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
	_name = rhs._name;
	_signed = false;
	_signGrade = rhs._signGrade;
	_execGrade = rhs._execGrade;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form " << ((Form)i).getName();
	o << (((Form)i).getSigned() ? " is" : " is not");
	o << " signed, it can be signed by bureaucrats level " << ((Form)i).getSignGrade() << (((Form)i).getSignGrade() > 1 ? " and up," : ",");
	o << " it can be executed by bureacrats level " << ((Form)i).getExecGrade() << (((Form)i).getExecGrade() > 1 ? " and up." : ".");
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

std::string	Form::getName()
{
	return (_name);
}

bool		Form::getSigned()
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

int			Form::getSignGrade()
{
	return (_signGrade);
}

void		Form::setSignGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	else
		_signGrade = grade;
}

int			Form::getExecGrade()
{
	return (_execGrade);
}

void		Form::setExecGrade(int grade)
{
	if (grade < 1)
		throw (GradeTooHighException());
	else if (grade > 150)
		throw (GradeTooLowException());
	else
		_execGrade = grade;
}

/* ************************************************************************** */