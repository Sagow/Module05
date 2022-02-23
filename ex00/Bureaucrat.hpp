#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>

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

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		std::string	getName() const;
		int			getGrade() const;
		void		promote();
		void		retrograde();
		void		setGrade(int grade);

	private:

		const std::string	_name;
		int			_grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */