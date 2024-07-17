#include "AForm.hpp"
#include <iostream>
#include "Bureaucrat.hpp"

// ----------------- canonical form + other constructor -------------------- //

AForm::AForm(): _grade_sign(0), _grade_exec(0) {}

AForm::AForm(const std::string& name, const int& grade_sign, const int& grade_exec, 
const std::string& target): _name(name), _signed(false), _grade_sign(grade_sign), 
_grade_exec(grade_exec), _target(target)
{
	if (grade_sign < 1 || grade_exec < 1)
		throw GradeTooHighException();
	if (grade_sign > 150 || grade_exec > 150)
		throw GradeTooLowException();
}

AForm::AForm( const AForm& copy ) : _name(copy._name), _signed(copy._signed), 
_grade_sign(copy._grade_sign), _grade_exec(copy._grade_exec), _target(copy._target) {}

AForm& AForm::operator=(const AForm& src )
{
	if (this != &src)
	{
		_signed = src._signed;
		_target = src._target;
	}
	return *this;
}

AForm::~AForm() {}

// ------------------------------- getters --------------------------------- //

const std::string& 	AForm::getName( void ) const
{
	return _name;
}

const bool&			AForm::getSigned( void ) const
{
	return _signed;
}

const int&			AForm::getGradeSign( void ) const
{
	return _grade_sign;
}

const int&			AForm::getGradeExec( void ) const
{
	return _grade_exec;
}

const std::string& 	AForm::getTarget( void ) const
{
	return _target;
}

// ------------------------------- setters --------------------------------- //

void	AForm::setSigned( const bool& is_signed )
{
	_signed = is_signed;
}

void	AForm::setTarget(const std::string& target)
{
	_target = target;
}

// ----------------------------- exceptions -------------------------------- //

const char* AForm::GradeTooLowException::what() const throw()
{
	return "their grade is too low";
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "their grade is too high";
}

const char* AForm::AlreadySignedException::what() const throw()
{
	return "the form is already signed";
}

const char* AForm::FormisNotSignedException::what() const throw()
{
	return "the form needs to be signed first";
}

// --------------------------- member function ----------------------------- //

void	AForm::beSigned( Bureaucrat& b )
{
	if (_signed)
		throw AlreadySignedException();
	if (b.getGrade() > _grade_sign)
		throw GradeTooLowException();
	else 
		_signed = true;
}

// -------------------------- insertion overload -------------------------- //

std::ostream& operator<<(std::ostream& output, const AForm& f)
{
	output << "Form " << BOLD << f.getName() << RESET << std::endl;
	std::cout << "~ is signed : " ;
	if (f.getSigned() == true) 
		output << BOLD << "yes" << RESET << std::endl;
	else 
		output << BOLD << "no" << RESET << std::endl;
	output << "~ need grade " << BOLD <<  f.getGradeSign() << RESET << " to be signed" << std::endl;
    output << "~ need grade " << BOLD <<  f.getGradeExec() << RESET << " to be executed" << std::endl;
	output << "~ target is: " << BOLD << f.getTarget() << RESET << std::endl;
	return output;
}