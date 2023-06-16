#pragma once
#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <stdbool.h>

class Bureaucrat;

class AForm {
	private:
		const std::string	_name;
		bool _signed;
		const int _signGrade;
		const int _execGrade;

	public:
		virtual void contract() = 0;
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
		void execute(Bureaucrat const &executor) const;

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

std::ostream &operator<<( std::ostream &out, AForm *insert );

#endif