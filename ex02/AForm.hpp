#ifndef AFORM_HPP
# define AFORM_HPP

	#include <string>
	#include <stdexcept>
	
	class Bureaucrat;

	class AForm {

		private:
		const std::string 	_name;
		bool				_signed;
		const int			_grade_sign;
		const int			_grade_exec;
		std::string			_target;

		public :
		AForm();
		AForm(const std::string& name, const int& grade_sign, const int& grade_exec, const std::string& target);
		AForm( const AForm& copy );
		AForm& operator=(const AForm& src );
		virtual ~AForm();

		// getters
		const std::string& 	getName( void ) const;
		const bool&			getSigned( void ) const;
		const int&			getGradeSign( void ) const;
		const int&			getGradeExec( void ) const;
		const std::string& 	getTarget( void ) const;

		// setters
		void	setSigned( const bool& is_signed );
		void	setTarget(const std::string& target);

		// member functions
		void	beSigned( Bureaucrat& b );
		virtual void	execute(Bureaucrat const & executor) const = 0;

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

		class FormisNotSignedException : public std::exception {
		public:
			const char* what() const throw();
		};
	};

	// insertion overload
	std::ostream& operator<<(std::ostream& output, const AForm& f);

#endif