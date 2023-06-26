#include "RobotomyRequestForm.hpp"

/*=============== CONSTRUCTOR ===============*/

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("RRF", 72, 45) {
	_target	= "Unknown";
	std::cout << "Robotomy Request Form " + getName() + " constructed." << std::endl;
}

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
	srand((unsigned) time(NULL));
	int random = rand() % 2;

	std::cout << "Execution status granted by " << executor.getName() << std::endl;
	std::cout << CYAN << "Initiating Robotomy on target: " << _target << std::endl;
	std::cout << "Bzzzzz.. Bzzzzzzzz.. " << RESET << std::endl;

	if (random)
		std::cout << "Target " << _target << " robotomized successfully.";
	else
		std::cout << "Target " << _target << " robotomy failed.";
	std::cout << std::endl;
}
