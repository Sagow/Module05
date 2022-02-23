#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "includes.h"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Intern &		operator=( Intern const & rhs );

		Form	*makeForm(std::string form, std::string target);

		class NotValidException : virtual public std::exception
		{
			virtual const char* what() const throw()
			{
				return ("This form does not exist");
			}
		};

	private:

		Form	*makePresidentialPardonForm(std::string target);
		Form	*makeRobotomyRequestForm(std::string target);
		Form	*makeShrubberyCreationForm(std::string target);
	
		std::string possibleForms[3];
		Form	*(Intern::*FormMethods[3])(std::string target);

};

#endif /* ********************************************************** INTERN_H */