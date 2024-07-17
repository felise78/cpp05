#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShruberryCreationForm::ShruberryCreationForm( const std::string& target ) : AForm("ShruberryCreationForm", 145, 137, target)
{
	this->setTarget(target);
}

ShruberryCreationForm::ShruberryCreationForm( const ShruberryCreationForm& copy ) : AForm(copy)
{
	*this = copy;
}

ShruberryCreationForm& ShruberryCreationForm::operator=( const ShruberryCreationForm& src )
{
	if (this != &src)
	{
		this->setSigned(src.getSigned());
		this->setTarget(src.getTarget());
	}
	return *this;
}

ShruberryCreationForm::~ShruberryCreationForm()
{

}

void	ShruberryCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeSign() || executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();

	else if (this->getSigned() == false)
		throw FormisNotSignedException();

	else
	{
		std::ofstream file((this->getTarget() + "_shrubbery").c_str());
		if (file.is_open())
		{
			file << "    *         *         *       *" << std::endl;
			file << "   ***       ***       ***     ***" << std::endl;
			file << "  *****     *****     *****   *****" << std::endl;
			file << " *******   *******   ******* *******" << std::endl;
			file << "********* ********* ********* *******" << std::endl;
			file << "   ***       ***       ***     ***" << std::endl;
			file << "   ***       ***       ***     ***" << std::endl;
			file.close();
		}
		else
			std::cerr << "Unable to create file." << std::endl;
	} 
}