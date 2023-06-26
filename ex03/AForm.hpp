#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <stdbool.h>
#include <iostream>
#include <fstream>

#define GREEN "\033[32;1m"
#define RED "\033[31m"
#define CYAN "\033[36;1m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		virtual void execute(Bureaucrat const &executor) const = 0;

		AForm( void );
		AForm( int sign, int exec );
		AForm( std::string name, int sign, int exec );
		AForm( const AForm &copy);
		AForm &operator=( const AForm &assign );
		virtual ~AForm( void );

		void setName( std::string name);
		void setSign( int sign );
		void setExec( int exec );
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

		// class UnsignedForm : public std::exception {
		// 	public:
		// 		virtual const char* what() const throw();
		// };
};

std::ostream &operator<<( std::ostream &out, AForm *insert );

#endif