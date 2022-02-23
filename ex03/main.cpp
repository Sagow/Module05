# include "includes.h"

int	main(void)
{
	Intern someRandomIntern;
	Form* robotomy;
	Form* pardon;
	Form* shrubbery;
	Form* neMarchePas;
	Bureaucrat chef("Grand Schtroumpf", 1);

	try
	{
		robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
		chef.signForm(*robotomy);
		delete robotomy;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		pardon = someRandomIntern.makeForm("presidential pardon", "Inox le voleur de croquettes");
		chef.signForm(*pardon);
		delete pardon;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		shrubbery = someRandomIntern.makeForm("shrubbery creation", "cat forest");
		chef.signForm(*shrubbery);
		delete shrubbery;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		neMarchePas = someRandomIntern.makeForm("formulaire inexistant", "Fantasia");
		chef.signForm(*neMarchePas);
		delete neMarchePas;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return (0);
}