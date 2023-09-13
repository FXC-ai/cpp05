#include "Bureaucrat.hpp"

void Bureaucrat::incrementGrade() 
{
	if (this->_grade - 1 < 1) 
	{
		throw GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade() 
{
	if (this->_grade + 1 > 150)
	{
		throw GradeTooLowException();
	}
	this->_grade++;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name)
{
	this->setGrade(grade);
	//std::cout << "Bureaucrat " << this->_name << " " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat() : _name("Default name"), _grade(150)
{
	//std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() 
{
	//std::cout << "Bureaucrat default destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
	return this->_name;
}

void Bureaucrat::setGrade(int grade)
{

	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	this->_grade = grade;

}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)
{
	if (this != &rhs)
	{
		//std::cout << "Bureaucrat assignment operator called" << std::endl;
		this->_grade = rhs._grade;
	}
	return *this;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void	Bureaucrat::signForm(AForm &formToSign)
{
	try
	{
		formToSign.beSigned(*this);
		std::cout << this->getName() << " signed " << formToSign.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << this->getName() << " couldn't sign " << formToSign.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(AForm const & form)
{
	if (form.execute(*this) == 1)
	{
		std::cout << this->getName() << " executed " << form.getName() << std::endl;
	}
	else
	{
		std::cout << this->getName() << " failed to execute " << form.getName() << std::endl;
	}
}


std::ostream& operator<<(std::ostream& os, const Bureaucrat &BureaucratToDisplay)
{
	os << BureaucratToDisplay.getName() << ", bureaucrat grade " << BureaucratToDisplay.getGrade();
	return os;
}