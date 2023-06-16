#pragma once
#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class Form {
	private:
		const std::string	_name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		Form( void );
		Form( int sign, int exec );
		Form( std::string name, int sign, int exec );
		Form( const Form &copy);
		Form &operator=( const Form &assign );
		~Form( void );

		int setGrade( int grade );

		std::string getName( void ) const;
		int	getExec( void ) const;
		int	getSign( void ) const;
		bool getStatus( void ) const;

		void beSigned( Bureaucrat *b );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormSigned : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream &operator<<( std::ostream &out, Form *insert );

#endif