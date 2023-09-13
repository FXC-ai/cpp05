#include "AForm.hpp"

void AForm::beSigned(Bureaucrat &bureaucratForSign)
{
	if (bureaucratForSign.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = 1;
	}
	else
	{
		throw GradeTooLowException();
	}
}

AForm::AForm() : _name("Default AForm"), _isSigned(0), _gradeToSign(1), _gradeToExecute(1)
{
};

AForm::~AForm()
{
};

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	this->_isSigned = 0;
	if (gradeToExecute > 150)
		throw GradeTooLowException();
	if (gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150)
		throw GradeTooLowException();
	if (gradeToSign < 1)
		throw GradeTooHighException();
};

std::string AForm::getName() const
{
	return this->_name;
};

int AForm::getGradeToSign() const
{
	return this->_gradeToSign;
};

int AForm::getGradeToExecute() const
{
	return this->_gradeToExecute;
};

bool AForm::getIsSigned() const
{
	return this->_isSigned;
};

AForm& AForm::operator=(const AForm &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
};

std::ostream& operator<<(std::ostream &out, AForm &formToDisplay)
{
	out << "            Name : " << formToDisplay.getName() << std::endl;
	out << "       Is signed : " << formToDisplay.getIsSigned() << std::endl;
	out << "   Grade to sign : " << formToDisplay.getGradeToSign() << std::endl;
	out << "Grade to execute : " << formToDisplay.getGradeToExecute();
	return out;
}