#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm( const std::string& target ) : AForm("PresidentialPardon", 25, 5, target)
{

}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm& copy ) : AForm(copy)
{

}

PresidentialPardonForm& PresidentialPardonForm::operator=( const PresidentialPardonForm& src )
{
	if (this != &src)
	{
		this->setSigned(src.getSigned());
		this->setTarget(src.getTarget());
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeSign() || executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else if (this->getSigned() == false)
		throw FormisNotSignedException();
	else 
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}