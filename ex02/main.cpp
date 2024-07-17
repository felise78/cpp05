#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main ()
{
	try
	{
		//AForm test; //cannot be instanciated.
		
		Bureaucrat john("John", 14);
		PresidentialPardonForm form1("Rick");
		RobotomyRequestForm form2("Rick again");
		ShruberryCreationForm form3("Always_rick");

		// test Presidential Pardon
		std::cout << std::endl << john << std::endl;		
		std::cout << GREEN << DIM << "--------------------------------" << RESET << std::endl;
		std::cout << std::endl << form1 << std::endl;
		std::cout << GREEN << "Trying to make John execute " << form1.getName()  << " form :" << RESET << std::endl;
		john.executeForm(form1);
		while (john.getGrade() != 2)
			john.incrementGrade();
		std::cout << DIM << john << RESET;
		john.signForm(form1);
		std::cout << std::endl << form1 << std::endl;
		john.executeForm(form1);
		std::cout << std::endl;

		// test RobotomyRequest 
		std::cout << GREEN << DIM << "--------------------------------" << RESET << std::endl << std::endl; 
		std::cout << form2 << std::endl;
		john.signForm(form2);
		john.executeForm(form2);
		std::cout << std::endl;
		john.executeForm(form2);
		std::cout << std::endl;

		// test ShruberryCreation
		std::cout << GREEN << DIM << "--------------------------------" << RESET << std::endl << std::endl; 
		std::cout << form3 << std::endl;
		std::cout << GREEN << "Trying to make John execute " << form3.getName()  << " form :" << RESET << std::endl;
		john.executeForm(form3);
		john.signForm(form3);
		john.executeForm(form3);


		std::cout << std::endl << GREEN << DIM << "--------------------------------" << RESET << std::endl; 

		// tests des constructeurs de copie
		std::cout << std::endl << GREEN << "Test of the copy constructors : " << RESET << std::endl;
		AForm *form4 = new RobotomyRequestForm(form2);
		std::cout << *form4 << std::endl;
		AForm *form5 = new PresidentialPardonForm(form1);
		std::cout << *form5 << std::endl;
		AForm *form6 = new ShruberryCreationForm(form3);
		std::cout << *form6 << std::endl;

		// tests des operateurs d'assignement
		std::cout << GREEN  << "Test of the assignment operators : " << RESET << std::endl;
		AForm *form7 = new RobotomyRequestForm("Dona");
		std::cout << *form7 << std::endl;
		*form7 = *form4;
		std::cout << *form7;

		std::cout << std::endl << GREEN << DIM << "--------------------------------" << RESET << std::endl;

		delete form4;
		delete form5;
		delete form6;
		delete form7;

		std::cout << std::endl << GREEN << "Trying to create a bureaucrat with an invalid grade :" << RESET << std::endl;
		Bureaucrat invalid("Invalid", 0);

		std::cout << "hello" << std::endl; // code is not excecuted after a catched error;
		// this is why I delete my allocations before the error
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
