#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include "includes.h"

class Form;

class Bureaucrat
{
	public:
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

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string	getName();
		int			getGrade();
		void		promote();
		void		retrograde();
		void		setGrade(int grade);

		void		signForm(Form &form);
		void		executeForm(Form const & form);

	private:

		std::string	_name;
		int			_grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */