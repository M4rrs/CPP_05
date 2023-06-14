#pragma once
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class Bureaucrat {
	private:
		const std::string	_name;
		int	_grade; 

	public:
		Bureaucrat( void );
		Bureaucrat( int grade );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat &copy);
		Bureaucrat &operator=( const Bureaucrat &assign );
		~Bureaucrat( void );

		std::string getName( void ) const;
		int	getGrade( void ) const;
		void setGrade( int grade );

		void promote( int promotion );
		void demote( int demotion );

		void signForm( Form f );

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

};

std::ostream &operator<<( std::ostream &out, Bureaucrat *insert );

#endif