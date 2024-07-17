#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	Intern intern;
	
	try {
		AForm *invalid;
		std::cout << GREEN << "Trying to make intern create an unknown form :" << RESET << std::endl;
		invalid = intern.makeForm("unknown form", "Carine");
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << GREEN << "Trying to make intern create a PresidentialPardon form :" << RESET << std::endl;
		AForm *form = intern.makeForm("presidential pardon", "Owen");
		std::cout << std::endl;
		try {
			Bureaucrat patron("Boss", 1);
			std::cout << "Making bureaucrat Boss sign and execute this form :" << std::endl << DIM;
			patron.signForm(*form);
			patron.executeForm(*form);
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		delete form;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << RESET << std::endl;

	try { // exemple du sujet
		AForm* rrf;
		std::cout << GREEN << "Trying to make intern create a RobotomyRequest form :" << RESET << std::endl;
		rrf = intern.makeForm("robotomy request", "Bender");
		delete rrf;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		std::cout << GREEN << "Trying to make intern create a ShrubberyCreation form :" << RESET << std::endl; 
		AForm *form = intern.makeForm("shrubbery creation", "Ricky");
		std::cout << std::endl;
		try { // oblige de creer Bureaucrat dans un try/catch car si il throw une erreur sans ca il y aura des leaks
			Bureaucrat patron("Bosse", 1);
			std::cout << "Trying to make bureaucrat Bosse sign and execute this form :" << std::endl << DIM;
			patron.executeForm(*form);
			patron.signForm(*form); // ici signForm s'execute car l'erreur de executeForm est catch dans la fonction
			patron.executeForm(*form);
			std::cout << RESET;
		} catch (const std::exception& e) {
			std::cerr << e.what() << std::endl;
		}
		delete form;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
