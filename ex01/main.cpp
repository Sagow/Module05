# include "Bureaucrat.hpp"
# include "Form.hpp"

int	main(void)
{
	try
	{
		std::cout << "Creating Normal" << std::endl;
		Form	normal("Normal", 50, 68);
		std::cout << normal << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Creating Trop bas" << std::endl;
		Form	tropBas("Trop bas", 50, 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::cout << "Creating Trop haut" << std::endl;
		Form	tropHaut("Trop haut", 0, 68);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	Bureaucrat Louise("Louise", 48);
	Bureaucrat Jeanne("Jeanne", 147);

	Form	A("A", 50, 68);
	Form	B("B", 50, 68);
	Form	C("C", 50, 68);
	Form	D("D", 50, 68);

	Louise.signForm(A);
	A.beSigned(Louise);
	B.beSigned(Louise);
	Jeanne.signForm(C);
	D.beSigned(Jeanne);
	return (0);
}