#include "Intern.hpp"

/*=============== CONSTRUCTOR ===============*/
Intern::Intern( void ) {
	std::cout << "Intern constructed." << std::endl;
}

/*=============== DESTRUCTOR ===============*/

Intern::~Intern( void ) {
	std::cout << "Intern destructed." << std::endl;
}
/*=============== COPY CONSTRUCTOR ===============*/

Intern::Intern( const Intern &copy ) {
	(void) copy;
	std::cout << "Intern cloned." << std::endl;
}

/*=============== OVERLOADED OPERATOR ===============*/

Intern &Intern::operator=( const Intern &assign ) {
	if (this != &assign)
		*this = assign;
	return (*this); 
}

/*=============== PUBLIC  ===============*/

AForm *Intern::ShrubberyForm( std::string target ) {
	AForm *ret;

	ret = new ShrubberyCreationForm(target);
	std::cout << CYAN
			<< "Intern created Shrubbery Creation Form. Form target is: "
			<< target << "." << RESET
			<< std::endl;
	return (ret);
}

AForm *Intern::RobotomyForm( std::string target ) {
	AForm *ret;

	ret = new RobotomyRequestForm(target);
	std::cout << CYAN
			<< "Intern created Robotomy Request Form. Form target is: "
			<< target << "." << RESET
			<< std::endl;
	return (ret);
}

AForm *Intern::PardonForm( std::string target ) {
	AForm *ret;

	ret = new PresidentialPardonForm(target);
	std::cout << CYAN
			<< "Intern created Presidential Pardon Form. Form target is: "
			<< target << "." << RESET
			<< std::endl;
	return (ret);
}

AForm *Intern::makeForm( std::string form, std::string target ) {

	typedef AForm *(Intern::*FormTypes)(std::string);

	FormTypes forms[3] = {&Intern::ShrubberyForm, &Intern::RobotomyForm, &Intern::PardonForm};
	std::string formNames[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	try {
		for (int i = 0; i < 3; i++) {
			if (form == formNames[i])
				return ((this->*forms[i])(target));
		}
		throw Intern::InvalidFormName();
	}
	catch (Intern::InvalidFormName &except) {
		std::cout << RED << except.what() << RESET << std::endl;
	}
	return NULL;
}

/*=============== EXCEPTION  ===============*/

const char* Intern::InvalidFormName::what() const throw() {
	return ("Invalid Form Name. Form does not exist.");
}
