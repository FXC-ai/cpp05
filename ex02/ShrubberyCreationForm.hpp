#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "Bureaucrat.hpp"
#include "AForm.hpp"

#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private :
		const std::string _target;

	public :
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string name, std::string target);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);



		virtual ~ShrubberyCreationForm();
		virtual bool execute(Bureaucrat const & executor) const;
	
};


#endif