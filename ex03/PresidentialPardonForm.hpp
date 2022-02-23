#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "includes.h"

class Bureaucrat;

class PresidentialPardonForm : virtual public Form
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( PresidentialPardonForm const & src );
		virtual ~PresidentialPardonForm();
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

		PresidentialPardonForm(std::string target);

		virtual  void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;

};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ****************************************** PRESIDENTIALPARDONFORM_H */