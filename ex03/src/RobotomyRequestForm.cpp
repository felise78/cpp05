#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm( const std::string& target ) : AForm("RobotomyRequestForm", 72, 45, target)
{

}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm& copy ) : AForm(copy)
{

}

RobotomyRequestForm& RobotomyRequestForm::operator=( const RobotomyRequestForm& src )
{
	if (this != &src)
	{
		this->setSigned(src.getSigned());
		this->setTarget(src.getTarget());
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{

}

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeSign() || executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else if (this->getSigned() == false)
		throw FormisNotSignedException();
	else
	{
		static int success = 0;
	
		std::cout << "Bzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << std::endl;
		if (success % 2 == 0)
			std::cout << _target << " has been robotomized successfully" << std::endl;
		else
			std::cout << "Oops, robotomy has failed" << std::endl;
		success++;
	}
}