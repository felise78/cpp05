#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main ()
{
	try
	{
		Bureaucrat john("John", 100);
		Form f("form_01", 15, 15);
		
		std::cout << GREEN << "Testing the Form insertion overload :" << RESET << std::endl;
		std::cout << f << std::endl;
		
		std::cout << GREEN << "Creating John : " << RESET <<  std::endl;
		std::cout << john;

		std::cout << GREEN << "Trying to make John sign the form : " << RESET <<  std::endl;
		john.signForm(f); // here an error is catch but the rest of the code here is executed
						  // because the error is catched in another function

		std::cout << GREEN << "Incrementing John's grade : " << RESET <<  std::endl;
		while (john.getGrade() != 15)
			john.incrementGrade();
		std::cout << john;

		std::cout << GREEN << "Trying again to make John sign the form : " << RESET <<  std::endl;
		john.signForm(f);

		std::cout << std::endl;
		std::cout << f;
		std::cout << std::endl;

		std::cout << GREEN << "Trying again to make John sign the same form : " << RESET <<  std::endl;
		std::cout << john;
		john.signForm(f);

		std::cout <<  std::endl;
		std::cout << GREEN << "Trying to create a bureaucrat with an invalid grade :" << RESET << std::endl;
		Bureaucrat invalid("Invalid", 0);
		std::cout << std::endl; // everything after a catched error is not executed
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
