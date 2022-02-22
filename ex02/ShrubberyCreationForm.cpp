#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137)
{
	_target = "Default";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137)
{
	_target = target;
}


ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src )
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor)
{
	try
	{
		execution(((Bureaucrat)executor).getGrade());
		std::fstream file;
		file.open(_target);
		file << "		              . . ." << std::endl;
		file << "                   .        .  .   \\  . /\\" << std::endl;
		file << "                .                 . )  ( \') .  ." << std::endl;
		file << "                                .  (  /  )" << std::endl;
		file << "                               .    \\(__)|       .." << std::endl;
		file << "               .          .            .              ." << std::endl;
		file << "               .            \'.,        .               ." << std::endl;
		file << "               .              \'b      *" << std::endl;
		file << "                .              \'$    \#.                .." << std::endl;
		file << "               .    .           $\:   \#:               ." << std::endl;
		file << "             ..      .  ..      *\#  \@):        .   . ." << std::endl;
		file << "                          .     :\@,\@):   ,.**:\'   ." << std::endl;
		file << "              .      .,         :\@\@*: ..**\'      .   ." << std::endl;
		file << "                       \'\#o.    .:(@\'.\@*\"\'  ." << std::endl;
		file << "               .  .       \'bq,..:,@@*'   ,*      .  ." << std::endl;
		file << "                          ,p$q8,:\@)\'  .p*\'      ." << std::endl;
		file << "                   .     \'  . \'\@\@Pp\@\@*\'    .  ." << std::endl;
		file << "                    .  . ..    Y7\'.\'     .  ." << std::endl;
		file << "                              :\@):." << std::endl;
		file << "                             .:\@:\'." << std::endl;
		file << "                           .::(\@:." << std::endl;
		file.close();
	}
	catch(const std::exception& e)
	{
		std::cout << "The form " << getName() << "couldn't be executed by " << ((Bureaucrat)executor).getName() << " because ";
		std::cerr << e.what() << '\n';
	}
	
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */