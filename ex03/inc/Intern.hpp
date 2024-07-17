#ifndef INTERN_HPP
# define INTERN_HPP

	#include <string>
	#include "AForm.hpp"

	// format / colors
	#define BOLD    "\033[1m"
	#define DIM     "\033[2m"
	#define GREEN   "\033[32m"
	#define RESET  	"\033[0m"

	class Intern {

		public :
		Intern();
		Intern( const Intern& copy );
		Intern& operator=( const Intern& copy );
		~Intern();

		AForm* 	makeForm(const std::string& name, const std::string& target);
		// AForm*	makePresidentialPardon(const std::string target);
		// AForm*	makeRobotomyRequest(const std::string target);
		// AForm*	makeShrubberyCreation(const std::string target);


		// exception
		class UnkownForm : public std::exception {
		public:
			virtual const char* what() const throw();
		};
	};

#endif