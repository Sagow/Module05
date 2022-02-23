# include "Bureaucrat.hpp"
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

int	main(void)
{
	PresidentialPardonForm	FormA("Marina");
	RobotomyRequestForm		FormB("Jean-Eudes");
	ShrubberyCreationForm	FormC("Jardin");
	PresidentialPardonForm	pasSigneA("Marina");
	RobotomyRequestForm		pasSigneB("Jean-Eudes");
	ShrubberyCreationForm	pasSigneC("Jardin");
	Bureaucrat				chef("Grand Schtroumpf", 1);
	Bureaucrat				Monique("Monique", 139);

	std::cout << std::endl;

	std::cout << chef.getName() << " va essayer (sans succes) d'executer les forms A, B, C non signees" << std::endl;
	chef.executeForm(FormA);
	chef.executeForm(FormB);
	chef.executeForm(FormC);

	std::cout << std::endl;

	std::cout << chef.getName() << " va signer les forms A, B, C" << std::endl;
	chef.signForm(FormA);
	chef.signForm(FormB);
	chef.signForm(FormC);

	std::cout << std::endl;

	std::cout << chef.getName() << " va executer les forms A, B, C" << std::endl;
	chef.executeForm(FormA);
	chef.executeForm(FormB);
	chef.executeForm(FormC);

	std::cout << std::endl;

	std::cout << Monique.getName() << " va essayer (sans succes) d'executer les forms A, B, C" << std::endl;
	Monique.executeForm(FormA);
	Monique.executeForm(FormB);
	Monique.executeForm(FormC);

	return (0);
}