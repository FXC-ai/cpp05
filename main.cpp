#include <iostream>
#include <string>
#include <exception>


class Bureaucrat
{

	public:
    	Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat& operator= (const Bureaucrat& rhs);
		~Bureaucrat();
		std::string getName();
		void setGrade(int grade);
		int getGrade();

		void incrementGrade();
		void decrementGrade();

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw();
		};


	private:	
		const std::string	_name;
		int					_grade;

};




void Bureaucrat::incrementGrade() 
{
	// if (_grade - 1 < 1) {
	// 	throw GradeTooHighException();
	// }
	this->_grade--;
}

void Bureaucrat::decrementGrade() 
{



	this->_grade++;
}

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat " << this->_name << " " << this->_grade << std::endl;
}

Bureaucrat::Bureaucrat() : _name("Default name"), _grade(150)
{
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() 
{
	std::cout << "Bureaucrat default destructor called" << std::endl;
}

std::string Bureaucrat::getName() 
{
	return this->_name;
}

void Bureaucrat::setGrade(int grade)
{

	this->_grade = grade;
	// if (this->_grade < 1)
	// 	throw GradeTooHighException();
	// else if (this->_grade > 150)
	// 	throw GradeTooLowException();

}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
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

int Bureaucrat::getGrade()
{
	return this->_grade;
}

int main() 
{

	std::cout << "------------Modele coplien---------------" << std::endl;
	std::cout << "Constructeur par défaut" << std::endl;
	Bureaucrat b;

	std::cout << "Constructeur avec paramètre" << std::endl;
	Bureaucrat b2("John", 5);

	std::cout << "Opérateur d assignation" << std::endl;
	std::cout << "grade de b : " << b.getGrade() << std::endl;
	
	b = b2;
	std::cout << "grade de b : " << b.getGrade() << std::endl;

	std::cout << "Constructeur de copie" << std::endl;
	Bureaucrat b3(b2);
	std::cout << "grade de b3 : " << b3.getGrade() << std::endl;


	std::cout << std::endl;
	std::cout << "------------Tests exercice---------------" << std::endl;



	//std::cout << b << std::endl;
	
	
	return 0;



}