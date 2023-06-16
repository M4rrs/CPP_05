#include "ShrubberyCreationForm.hpp"

/*=============== CONSTRUCTOR ===============*/

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : AForm("SCF", 145, 137) {
	_target	= target;
}
/*=============== DESTRUCTOR ===============*/

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {
	std::cout << "Form " + _name + " destructed." << std::endl;
}

/*=============== COPY CONSTRUCTOR ===============*/
/*=============== OVERLOADED OPERATOR ===============*/
/*=============== PUBLIC  ===============*/
