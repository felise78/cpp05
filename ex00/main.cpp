#include <iostream>
#include "Bureaucrat.hpp"

int main ()
{
	try
	{
		Bureaucrat john("John", 100);

		std::cout << GREEN << "Testing the Bureaucrat insertion overload : " << RESET << std::endl;
		std::cout << john << std::endl;

		std::cout << GREEN << "Testing incrementGrade() : " << RESET << std::endl;
		john.incrementGrade();
		std::cout << "Incremented Grade: " << john.getGrade() << std::endl;
		std::cout << std::endl;

		std::cout << GREEN << "Testing decrementGrade() : " << RESET << std::endl;
		john.decrementGrade();
		std::cout << "Decremented Grade: " << john.getGrade() << std::endl;
		std::cout << std::endl;

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