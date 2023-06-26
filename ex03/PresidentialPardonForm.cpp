#include "PresidentialPardonForm.hpp"

/*=============== CONSTRUCTOR ===============*/

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("PPF", 25, 5) {
	_target	= "Unknown";
	std::cout << "Presidential Pardon Form " + getName() + " constructed." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PPF", 25, 5) {
	_target	= target;
	std::cout << "Presidential Pardon Form " + getName() + " constructed." << std::endl;
}
/*=============== DESTRUCTOR ===============*/

PresidentialPardonForm::~PresidentialPardonForm( void ) {
	std::cout << "Form " + getName() + " destructed." << std::endl;
}

/*=============== COPY CONSTRUCTOR ===============*/

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy ) : AForm( copy ) {
	*this = copy;
	std::cout << "PPF " + getName() + " cloned." << std::endl;
}

/*=============== OVERLOADED OPERATOR ===============*/

PresidentialPardonForm &PresidentialPardonForm::operator=( const PresidentialPardonForm &assign ) {
	this->_target = assign._target;
	return (*this); 
}

/*=============== PUBLIC  ===============*/

void PresidentialPardonForm::execute( Bureaucrat const &executor ) const {
	std::cout << "Execution status granted by " << executor.getName() << std::endl;
	std::cout << CYAN
			<< "This is to announce that " << _target
			<< " has been pardoned by President Zaphod Beeblebrox."
			<< RESET
			<< std::endl;
}
