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
		std::cout << "Bureaucrat assignment operator called" << std::endl;
		this->_grade = rhs._grade;
	}
	return *this;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat &BureaucratToDisplay)
{
	os << BureaucratToDisplay.getName() << ", bureaucrat grade " << BureaucratToDisplay.getGrade();
	return os;
}