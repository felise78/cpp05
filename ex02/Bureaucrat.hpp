#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>
#include <stdexcept>
#include "AForm.hpp"

// format / colors
#define BOLD    "\033[1m"
#define DIM     "\033[2m"
#define GREEN   "\033[32m"
#define RESET  	"\033[0m"

class Bureaucrat {
	
	private : 
	const std::string	_name;
	int					_grade;

	public : 
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat( const Bureaucrat &copy );
	Bureaucrat& operator=( const Bureaucrat &src );
	~Bureaucrat();

	// getters
	const std::string & getName( void ) const;
	int getGrade( void ) const;

	// exceptions
	class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

	// member functions
	void	incrementGrade( void ); 
	void	decrementGrade( void );
	void 	signForm( AForm& form );
	void 	executeForm(AForm const & form);
};

// insertion overload
std::ostream& operator<<(std::ostream& output, const Bureaucrat& b);

#endif