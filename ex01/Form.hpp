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

		Form(std::string name, int sign, int exec);

		std::string	getName() const;
		bool		getSigned() const;
		void		setSigned(int grade);
		int			getSignGrade() const;
		int			getExecGrade() const;

		void		beSigned(Bureaucrat &bureaucrat);

	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */