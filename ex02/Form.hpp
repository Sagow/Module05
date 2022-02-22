#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{

	public:

		Form();
		Form( Form const & src );
		~Form();
		Form &		operator=( Form const & rhs );

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("The grade is too high!");
			}
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "The grade is too low!";
			}
		};

		class AlreadySignedException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "the form is already signed!";
			}
		};

		class NotSignedException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "the form is not signed!";
			}
		};

		Form(std::string name, int sign, int exec);

		std::string	getName();
		void		setName(std::string name);
		bool		getSigned();
		void		setSigned(int grade);
		int			getSignGrade();
		void		setSignGrade(int grade);
		int			getExecGrade();
		void		setExecGrade(int grade);
		void		execution(int grade);

		void		beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) = 0;

	private:

		std::string	_name;
		bool		_signed;
		int			_signGrade;
		int			_execGrade;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */