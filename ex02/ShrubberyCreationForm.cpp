#include "ShrubberyCreationForm.hpp"


ShrubberyCreationForm::ShrubberyCreationForm (std::string name, std::string target) : AForm(name, 145, 137), _target(target)
{

};

ShrubberyCreationForm::ShrubberyCreationForm () : AForm("default_name", 145, 137), _target("default_target")
{

};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (*this != rhs)
	{
		
		this->_target = rhs._target;
	}
	return *this;
};


ShrubberyCreationForm::~ShrubberyCreationForm(){};

bool ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

	if (executor.getGrade() <= this->getGradeToExecute())
	{

		if (this->getIsSigned() == 1)
		{
			std::string fileName;
			fileName = this->_target + "_shrubbery";

			std::ofstream monFlux(fileName.c_str());

			monFlux << "       ^^       " <<std::endl;
			monFlux << "      ^O^^      " <<std::endl;
			monFlux << "     ^^^^^^     " <<std::endl;
			monFlux << "    ^~~~~~~^    " <<std::endl;
			monFlux << "   ^^O^^^^^^^   " <<std::endl;
			monFlux << "  ^^^^^^^^^^^^  " <<std::endl;
			monFlux << " ^^^^^^^^^^^O^^ " <<std::endl;
			monFlux << "O^^^^^^^^^^^^^^^" <<std::endl;
			monFlux << "       ||       " <<std::endl;
			monFlux << "______/  \\______" <<std::endl;

			monFlux.close();

			//std::cout << executor.getName() << " executed " << this->getName() << std::endl;
			return 1;
		}
		else
		{
			//std::cout << this->getName() << " is not signed" << std::endl;
			return 0;
		}
	}
	else
	{
		throw GradeTooLowException();
	}
};