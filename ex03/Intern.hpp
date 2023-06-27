#pragma once
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class AForm;

class Intern {
	public:
		Intern( void );
		Intern( const Intern &copy );
		Intern &operator=( const Intern &assign );
		~Intern( void );

		AForm *makeForm( std::string form, std::string target );
		AForm *ShrubberyForm( std::string target );
		AForm *RobotomyForm( std::string target );
		AForm *PardonForm( std::string target );
		
		class InvalidFormName : std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif