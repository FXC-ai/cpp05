#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public :
		Intern();
		Intern(const Intern &src);
		~Intern();

		Intern &operator=(const Intern &rhs);

		AForm *makeForm(std::string formName, std::string target);
};

Intern::Intern(){};

Intern::Intern(const Intern &src)
{
	(void) src;
};

Intern::~Intern(){};

Intern& Intern::operator=(const Intern &rhs)
{
	(void) rhs;
	return *this;
}

AForm* Intern::makeForm(std::string formName, std::string target)
{
	(void) formName;
	(void) target;

	AForm *form00 = NULL;

	std::cout << strcmp("bk", "bk") << std::endl;


	if (strcmp("bk", "bk") == 0)
	{
		std::cout << "OUI" << std::endl;
	}

	return form00;

}

int main()
{

	Intern intern0;

	intern0.makeForm("","");



	return 0;
}