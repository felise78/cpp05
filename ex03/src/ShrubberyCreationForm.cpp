#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm( const std::string& target ) : AForm("ShrubberyCreationForm", 145, 137, target)
{
	_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm& copy ) : AForm(copy)
{
	*this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=( const ShrubberyCreationForm& src )
{
	if (this != &src)
	{
		this->setSigned(src.getSigned());
		this->setTarget(src.getTarget());
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{

}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->getGradeSign() || executor.getGrade() > this->getGradeExec())
		throw GradeTooLowException();
	else if (this->getSigned() == false)
		throw FormisNotSignedException();
	else
	{
		std::ofstream file((_target + "_shrubbery").c_str());
		if (file.is_open())
		{
			file << "    *         *         *       *" << std::endl;
			file << "   ***       ***       ***     ***" << std::endl;
			file << "  *****     *****     *****   *****" << std::endl;
			file << " *******   *******   ******* *******" << std::endl;
			file << "********* ********* ********* *******" << std::endl;
			file << "   ***       ***       ***     ***" << std::endl;
			file << "   ***       ***       ***     ***" << std::endl;
			file << "                       |||" << std::endl;
			file.close();
		}
		else
			std::cerr << "Unable to create file." << std::endl;
	} 
}