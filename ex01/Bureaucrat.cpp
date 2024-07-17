#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

// --------------------------- canonical form ------------------------------ //

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	else 
		_grade = grade;
}

Bureaucrat::Bureaucrat( const Bureaucrat& copy )
{
	*this = copy;
}

Bureaucrat& Bureaucrat::operator=( const Bureaucrat& src )
{
	_grade = src._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{

}

// ------------------------------- getters --------------------------------- //

const std::string & Bureaucrat::getName( void ) const
{
	return _name;
}

int Bureaucrat::getGrade( void ) const
{
	return _grade;
}

// --------------------------- member functions ---------------------------- //

void Bureaucrat::incrementGrade( void )
{
    if (_grade == 1)
        throw GradeTooHighException();
    else
        _grade--;
}

void Bureaucrat::decrementGrade( void )
{
    if (_grade == 150)
        throw GradeTooLowException();
    else
        _grade++;
}

void Bureaucrat::signForm( Form& form )
{
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    }
    catch(const std::exception& e) {
        std::cerr << _name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
    }
}

// ----------------------------- exceptions -------------------------------- //

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade too low";
}

// -------------------------- insertion overload -------------------------- //

std::ostream& operator<<(std::ostream& output, const Bureaucrat& b)
{
    output << b.getName() << ", bureaucrat grade " << b.getGrade() << "." << std::endl;
    return output;
}