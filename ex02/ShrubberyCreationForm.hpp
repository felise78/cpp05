#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

	#include "AForm.hpp"

	class ShruberryCreationForm : public AForm {

		public:
		ShruberryCreationForm( const std::string& target );
		ShruberryCreationForm( const ShruberryCreationForm& copy );
		ShruberryCreationForm& operator=( const ShruberryCreationForm& src );
		~ShruberryCreationForm();

		void	execute(Bureaucrat const & executor) const;

	};

#endif