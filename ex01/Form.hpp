#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

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

		Form(std::string name, int sign, int exec);

		std::string	getName();
		bool		getSigned();
		int			getSignGrade();
		void		setSignGrade(int grade);
		int			getExecGrade();
		void		setExecGrade(int grade);


	private:

		std::string	_name;
		bool		_signed;
		int			_signGrade;
		int			_execGrade;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );

#endif /* ************************************************************ FORM_H */