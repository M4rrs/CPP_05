#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
		ShrubberyCreationForm( void );

	public:
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( const ShrubberyCreationForm &copy);
		ShrubberyCreationForm &operator=( const ShrubberyCreationForm &assign );
		virtual ~ShrubberyCreationForm( void );

		void	createShrub( void );
}

#endif