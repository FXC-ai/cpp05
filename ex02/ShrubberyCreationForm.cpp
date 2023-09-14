#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm () : AForm("default_name", 145, 137), _target("default_target")
{
};

ShrubberyCreationForm::ShrubberyCreationForm (std::string name, std::string target) : AForm(name, 145, 137), _target(target)
{
};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src), _target(src.getTarget())
{
};

ShrubberyCreationForm::~ShrubberyCreationForm()
{

};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	AForm::operator=(rhs);
	return *this;
};

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{

	if (executor.getGrade() <= this->getGradeToExecute())
	{
		if (this->getIsSigned() == 1)
		{
			std::string fileName;
			fileName = this->_target + "_shrubbery";

			std::ofstream monFlux(fileName.c_str());

			monFlux << "       ^^       " <<std::endl;
			monFlux << "      ^O~^      " <<std::endl;
			monFlux << "     ^~~~~^     " <<std::endl;
			monFlux << "    ^~~~~~~^    " <<std::endl;
			monFlux << "   ^~O~~~~~~^   " <<std::endl;
			monFlux << "  ^~~~~~~~~~~^  " <<std::endl;
			monFlux << " ^^^^^^^^^^^O^^ " <<std::endl;
			monFlux << "O~~~~~~~~~~~~~~^" <<std::endl;
			monFlux << "       ||       " <<std::endl;
			monFlux << "______/  \\______" <<std::endl;

			monFlux.close();
		}
		else
		{
			throw FormNotSignedException();
		}
	}
	else
	{
		throw GradeTooLowException();
	}
};