#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

	#include "AForm.hpp"

	class RobotomyRequestForm : public AForm {

		public:
		RobotomyRequestForm( const std::string& target );
		RobotomyRequestForm( const RobotomyRequestForm& copy );
		RobotomyRequestForm& operator=( const RobotomyRequestForm& src );
		~RobotomyRequestForm();

		void	execute(Bureaucrat const & executor) const;

	};

#endif