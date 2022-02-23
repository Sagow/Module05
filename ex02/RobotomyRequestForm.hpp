#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <time.h>
# include <cstdlib>
# include "includes.h"

class Bureaucrat;

class RobotomyRequestForm : virtual public Form
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm const & src );
		virtual ~RobotomyRequestForm();
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

		RobotomyRequestForm(std::string target);


		virtual void	execute(Bureaucrat const & executor) const;

	private:
		std::string	_target;


};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ********************************************* ROBOTOMYREQUESTFORM_H */