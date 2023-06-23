#include "RobotomyRequestForm.hpp"

/*=============== CONSTRUCTOR ===============*/

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm("RRF", 72, 45) {
	_target	= target;
	std::cout << "Robotomy Request Form " + getName() + " constructed." << std::endl;
}
/*=============== DESTRUCTOR ===============*/

RobotomyRequestForm::~RobotomyRequestForm( void ) {
	std::cout << "Form " + getName() + " destructed." << std::endl;
}

/*=============== COPY CONSTRUCTOR ===============*/

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &copy ) : AForm( copy ) {
	*this = copy;
	std::cout << "RRF " + getName() + " cloned." << std::endl;
}

/*=============== OVERLOADED OPERATOR ===============*/

RobotomyRequestForm &RobotomyRequestForm::operator=( const RobotomyRequestForm &assign ) {
	this->_target = assign._target;
	return (*this); 
}

/*=============== PUBLIC  ===============*/

void RobotomyRequestForm::execute( Bureaucrat const &executor ) const {
	
}
