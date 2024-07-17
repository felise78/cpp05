#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern( const Intern& copy )
{
	*this = copy;
}

Intern& Intern::operator=( const Intern& copy )
{
	(void)copy;
	return *this;
}

Intern::~Intern() {}

// -------------------------- fonction membre ---------------------------//

static AForm	*makePresidentialPardon(const std::string target)
{
	return (new PresidentialPardonForm(target));
}

static AForm	*makeRobotomyRequest(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*makeShrubberyCreation(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm 	*Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm	*(*fct[3])(std::string target) = {&makePresidentialPardon, makeRobotomyRequest, makeShrubberyCreation};
	std::string	forms[3] = {"presidential pardon", "robotomy request", "shrubbery creation"};
	AForm*	form = NULL;
	for (int i = 0; i < 3; i++)
	{
		if (name == forms[i])
			form = fct[i](target);
	}
	if (form)
		std::cout << "Intern creates " << BOLD << form->getName() << RESET << std::endl;
	else
		throw (Intern::UnkownForm());
	return (form);
}

// --------------------------- exception ------------------------------ //

const char* Intern::UnkownForm::what() const throw()
{
	return ("Unknown Form");
}