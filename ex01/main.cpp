#include "Bureaucrat.hpp"


class Form
{

	private :
		const std::string	_name;
		bool 				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public :
		Form();
		Form(std::string name, int gradeToSign, int gradeToExecute);
		Form(const Form &src);
		Form& operator=(const Form &rhs);
		~Form();

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;

		void beSigned(Bureaucrat &bureaucratForSign);

		class GradeTooHighException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too High !!!";
			}
		};

		class GradeTooLowException : public std::exception
		{
			virtual const char* what() const throw()
			{
				return "Grade too Low !!!";
			}
		};
};

void Form::beSigned(Bureaucrat &bureaucratForSign)
{
	if (bureaucratForSign.getGrade() <= this->_gradeToSign)
	{
		this->_isSigned = 1;
	}
}

Form::Form() : _name("Default Form"), _isSigned(0), _gradeToSign(1), _gradeToExecute(1)
{
};

Form::~Form()
{
};

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : _name(name), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
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

std::string Form::getName() const
{
	return this->_name;
};

int Form::getGradeToSign() const
{
	return this->_gradeToSign;
};

int Form::getGradeToExecute() const
{
	return this->_gradeToExecute;
};

bool Form::getIsSigned() const
{
	return this->_isSigned;
};

Form& Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		this->_isSigned = rhs._isSigned;
	}
	return *this;
};




// std::ostream& operator<<(std::ostream &out, Form &formToDisplay)
// {

// 	out << "" << std::endl;
// 	return out;

// }
//Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs)


int main()
{

	std::cout << "--------- Modèle coplien --------" << std::endl;
	Form Form1;
	Form Form2("Law for water quality protection.", 10, 9);

	try
	{
		Form Form3("Law for keeping alive the hope.", 59, -98);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	Bureaucrat viola("Viola", 1);

	//Form2.beSigned(&viola);
	


	return 0;
}