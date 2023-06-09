#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <time.h>
class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
		RobotomyRequestForm( void );

	public:
		RobotomyRequestForm( std::string target );
		RobotomyRequestForm( const RobotomyRequestForm &copy);
		RobotomyRequestForm &operator=( const RobotomyRequestForm &assign );
		virtual ~RobotomyRequestForm( void );

		void robotomize( std::string target );
		void execute( Bureaucrat const &executor ) const;
};

#endif