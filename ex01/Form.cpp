#include "Form.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

// --------------------------- canonical form ------------------------------ //

Form::Form(): _grade_sign(0), _grade_exec(0) {}

Form::Form(const std::string& name, const int& grade_sign, const int& grade_exec): 
_name(name), _signed(false), _grade_sign(grade_sign), _grade_exec(grade_exec)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
}

Form::Form( const Form& copy ) : _name(copy._name), _signed(copy._signed), 
	_grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec)
{
	
}

Form& Form::operator=(const Form& src )
{
	_signed = src._signed;
	return *this;
}

Form::~Form()
{

}

// ------------------------------- getters --------------------------------- //

const std::string& 	Form::getName( void ) const
{
	return _name;
}

const bool&			Form::getSigned( void ) const
{
	return _signed;
}

const int&			Form::getGradeSign( void ) const
{
	return _grade_sign;
}

const int&			Form::getGradeExec( void ) const
{
	return _grade_exec;
}

// ----------------------------- exceptions -------------------------------- //

const char* Form::GradeTooLowException::what() const throw()
{
	return "their grade is too low";
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "their grade is too high";
}

const char* Form::AlreadySignedException::what() const throw()
{
	return "the form is already signed";
}

// --------------------------- member function ----------------------------- //

void	Form::beSigned( Bureaucrat& b )
{
	if (_signed)
		throw AlreadySignedException();
	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	else 
		_signed = true;
}

// -------------------------- insertion overload --------------------------- //

std::ostream& operator<<(std::ostream& output, const Form& f)
{
	output << "Form " << BOLD << f.getName() << RESET << std::endl;
	std::cout << "~ is signed : " ;
	if (f.getSigned() == true) 
		output << BOLD << "yes" << RESET << std::endl;
	else 
		output << BOLD << "no" << RESET << std::endl;
	output << "~ need grade " << BOLD <<  f.getGradeSign() << RESET << " to be signed" << std::endl;
    output << "~ need grade " << BOLD <<  f.getGradeExec() << RESET << " to be executed" << std::endl;
	return output;
}