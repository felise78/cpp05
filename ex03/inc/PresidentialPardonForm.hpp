#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

	#include "AForm.hpp"

	class PresidentialPardonForm : public AForm {

		public:
		PresidentialPardonForm( const std::string& target );
		PresidentialPardonForm( const PresidentialPardonForm& copy );
		PresidentialPardonForm& operator=( const PresidentialPardonForm& src );
		~PresidentialPardonForm();

		void	execute(Bureaucrat const & executor) const;
	};

#endif