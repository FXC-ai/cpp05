#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

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

AForm* Intern::makeForm(const std::string formName, const std::string target)
{
	const std::string tab[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
	int id_form;
	int i;
	AForm *tabForms[3];
	
	id_form = -1;
	i = 0;
	tabForms[0] = new ShrubberyCreationForm(formName, target); 
	tabForms[1] = new RobotomyRequestForm(formName, target); 
	tabForms[2] = new PresidentialPardonForm(formName, target); 

	while (i < 3)
	{
		if (tab[i].compare(formName) != 0)
			delete tabForms[i];
		else
			id_form = i;
		i++;
	}

	if (id_form != -1)
	{
		std::cout << "Intern creates " << formName << std::endl;
		return tabForms[id_form];
	}
	std::cout << "Intern can not creates " << formName << std::endl;
	return nullptr;
}

int main()
{
	
	Intern		james;
	Bureaucrat	parmelin("Guy Parmelin", 1);

	std::cout << "------------------ Test Robotomy ------------------" << std::endl;
	AForm *RobotomyRequestForm0 = james.makeForm("RobotomyRequestForm","42 Lausanne");
	parmelin.signForm(*RobotomyRequestForm0);
	parmelin.executeForm(*RobotomyRequestForm0);
	delete RobotomyRequestForm0;
	std::cout << std::endl;

	std::cout << "------------------ Test Shrubbery ------------------" << std::endl;
	AForm *ShrubberyCreationForm0 = james.makeForm("ShrubberyCreationForm","Saxon");
	parmelin.signForm(*ShrubberyCreationForm0);
	parmelin.executeForm(*ShrubberyCreationForm0);
	delete ShrubberyCreationForm0;
	std::cout << std::endl;


	std::cout << "------------------ Test Presidential Pardon ------------------" << std::endl;
	AForm *PresidentialPardonForm0 = james.makeForm("PresidentialPardonForm","Ford Perfect");
	parmelin.signForm(*PresidentialPardonForm0);
	parmelin.executeForm(*PresidentialPardonForm0);
	delete PresidentialPardonForm0;
	std::cout << std::endl;	

	std::cout << "------------------ Test False Form ------------------" << std::endl;
	AForm *FalseForm0 = james.makeForm("FalseForm","Bale");
	(void) FalseForm0;
	std::cout << std::endl;	

	return 0;
}