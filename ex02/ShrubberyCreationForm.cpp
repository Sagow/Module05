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
	*this = src;
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
	_signed = rhs._signed;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << i.getName();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	execution(((Bureaucrat)executor).getGrade());
	std::ofstream file;
	file.open((_target + "_shrubbery").c_str());
	file << " 	                   . . ." << std::endl;
	file << "                   .        .  .   \\  . /\\" << std::endl;
	file << "                .                 . )  ( \') .  ." << std::endl;
	file << "                                .  (  /  )" << std::endl;
	file << "                               .    \\(__)|       .." << std::endl;
	file << "               .          .            .              ." << std::endl;
	file << "               .            \'.,        .               ." << std::endl;
	file << "               .              \'b      *" << std::endl;
	file << "                .              \'$    #.                .." << std::endl;
	file << "               .    .           $:   #:               ." << std::endl;
	file << "             ..      .  ..      *#  @):        .   . ." << std::endl;
	file << "                          .     :@,@):   ,.**:'   ." << std::endl;
	file << "              .      .,         :@@*: ..**'      .   ." << std::endl;
	file << "                       \'#o.    .:(@\'.@*\"'  ." << std::endl;
	file << "               .  .       \'bq,..:,@@*'   ,*      .  ." << std::endl;
	file << "                          ,p$q8,:@)\'  .p*\'      ." << std::endl;
	file << "                   .     \'  . \'@@Pp@@*\'    .  ." << std::endl;
	file << "                    .  . ..    Y7\'.\'     .  ." << std::endl;
	file << "                              :@):." << std::endl;
	file << "                             .:@:\'." << std::endl;
	file << "                           .::(@:." << std::endl;
	file.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */