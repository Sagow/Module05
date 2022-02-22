#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

class Form;

class Bureaucrat
{
	public:
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