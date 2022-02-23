#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

class Bureaucrat;

class Form
{
	public:

		Form();
		Form( Form const & src );
		virtual ~Form();
		Form &		operator=( Form const & rhs );

		class GradeTooHighException : virtual public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("The grade is too high!");
			}
		};

		class GradeTooLowException : virtual public std::exception
		{
			virtual const char* what() const throw()
			{
				return "The grade is too low!";
			}
		};

		class AlreadySignedException : virtual public std::exception
		{
			virtual const char* what() const throw()
			{
				return "the form is already signed!";
			}
		};

		class NotSignedException : virtual public std::exception
		{
			virtual const char* what() const throw()
			{
				return "the form is not signed!";
			}
		};

		Form(std::string name, int sign, int exec);

		std::string	getName() const;
		bool		getSigned() const;
		void		setSigned(int grade);
		int			getSignGrade() const;
		void		setSignGrade(int grade);
		int			getExecGrade() const;
		void		setExecGrade(int grade);
		void		execution(int grade) const;

		void		beSigned(Bureaucrat &bureaucrat);
		virtual void	execute(Bureaucrat const & executor) const = 0;

	private:

		const std::string	_name;
		bool				_signed;
		const int			_signGrade;
		const int			_execGrade;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

# include "Bureaucrat.hpp"

#endif /* ************************************************************ FORM_H */