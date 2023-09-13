#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include "ShrubberyCreationForm.hpp"

int main()
{

	//AForm formTest;

	Bureaucrat	rosti("Rosti", 14);

	rosti.incrementGrade();

	ShrubberyCreationForm  Testpoire("Poirier", "Lausanne");

	rosti.signForm(Testpoire);

	//std::cout << Testpoire;
	try
	{
		rosti.executeForm(Testpoire);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	



	return 0;
}