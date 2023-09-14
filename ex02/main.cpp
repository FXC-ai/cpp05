#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{

	std::cout << "------------ TEST : = Modèle coplien de AForm ------------" << std::endl;


	std::cout << std::endl;


	//AForm formTest;

	Bureaucrat	rosti("Rosti", 14);

	rosti.incrementGrade();

	ShrubberyCreationForm  Testpoire("Poirier", "Lausanne");

	rosti.signForm(Testpoire);
	rosti.signForm(Testpoire);

	rosti.executeForm(Testpoire);

	return 0;
}