# include "Bureaucrat.hpp"

int	main(void)
{
	Bureaucrat	Jean_Louis("Jean-Louis", 15);
	Bureaucrat	chef("Grand Schtroumpf", 1);
	Bureaucrat	stagiaire;
	Bureaucrat	machineACafe("La machine a cafe", 164);
	Bureaucrat	Jeanne("Jeanne", -2);

	std::cout << Jean_Louis << std::endl;
	std::cout << stagiaire << std::endl;
	std::cout << chef << std::endl << std::endl;

	std::cout << "Promoting" << std::endl;
	Jean_Louis.promote();
	std::cout << Jean_Louis << std::endl;
	Jean_Louis.retrograde();
	stagiaire.promote();
	std::cout << stagiaire << std::endl << std::endl;
	stagiaire.retrograde();
	chef.promote();

	std::cout << "Retrograding" << std::endl;
	Jean_Louis.retrograde();
	std::cout << Jean_Louis << std::endl;
	chef.retrograde();
	std::cout << chef << std::endl;
	stagiaire.retrograde();
	
	return (0);
}