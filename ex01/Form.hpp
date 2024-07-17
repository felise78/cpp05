#ifndef FORM_HPP
#define FORM_HPP

	#include <string>
	#include <stdexcept>
	
	class Bureaucrat;

	class Form {

		private:
		const std::string 	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exec;

		public :
		Form();
		Form(const std::string& name, const int& grade_sign, const int& grade_exec);
		Form( const Form& copy );
		Form& operator=(const Form& src );
		~Form();

		// getters
		const std::string& 	getName( void ) const;
		const bool&			getSigned( void ) const;
		const int&			getGradeSign( void ) const;
		const int&			getGradeExec( void ) const;

		// member function
		void	beSigned( Bureaucrat& b );

		// exceptions
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw();
		};

		class AlreadySignedException : public std::exception {
		public:
			const char* what() const throw();
		};
	};

	// insertion overload
	std::ostream& operator<<(std::ostream& output, const Form& f);

#endif