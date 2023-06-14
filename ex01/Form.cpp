#include "Form.hpp"

/*=============== CONSTRUCTOR ===============*/

Form::Form( void ) : _name("Unknown"), _signGrade(75), _execGrade(1) {
	_signed = false;
	std::cout << "Default Form " + _name + " constructed." << std::endl;
}

Form::Form( int sign, int exec ) : _name("Unknown"), _signGrade(setGrade(sign)), _execGrade(setGrade(_execGrade)) {
	_signed = false;
	std::cout << "Grade instantiated Form " + _name + " constructed." << std::endl;
}

Form::Form( std::string name, int sign, int exec ) : _name(name), _signGrade(setGrade(sign)), _execGrade(setGrade(_execGrade)){
	_signed = false;
	std::cout << "Form " + _name + " constructed." << std::endl;
}

/*=============== DESTRUCTOR ===============*/

Form::~Form( void ) {
	std::cout << "Form " + _name + " destructed." << std::endl;
}

/*=============== COPY CONSTRUCTOR ===============*/

Form::Form( const Form &copy ) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
	*this = copy;
	std::cout << "Form " + this->_name + " cloned." << std::endl;
}

/*=============== OVERLOADED OPERATOR ===============*/

Form &Form::operator=( const Form &assign ) {

	this->_signed = assign._signed;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, Form *insert ) {
	out << insert->getName() + ": Grade to sign[ " << insert->getSign()
		<< " ] Grade to execute[ " << insert->getExec() << " ]\n"
		<< "Current form status[ " << insert->getStatus()
		<< std::endl;
	return (out);
}

/*=============== PUBLIC  ===============*/

std::string Form::getName( void ) const {
	return (_name);
}

int	Form::getSign( void ) const {
	return(_signGrade);
}

int	Form::getExec( void ) const {
	return(_execGrade);
}

bool	Form::getStatus( void ) const {
	return(_signed);
}

int Form::setGrade( int grade ) {
	try {
		if (grade >= 1 && grade <= 150)
			return(grade);
		else if (grade < 1)
			throw Form::GradeTooHighException();
		else if (grade > 150)
			throw Form::GradeTooLowException();
	}
	catch (Form::GradeTooHighException &except) {
		return(1);
		std::cout << except.what() << "\033[31m Grade set to maximum (1)\033[0m"
			 << std::endl;
	}
	catch (Form::GradeTooLowException &except) {
		return(150);
		std::cout << except.what() << "\033[31m Grade set to maximum (1)\033[0m"
			 << std::endl;
	}
}

void beSigned( Bureaucrat b ) {

}

/*=============== 	EXCEPTION  ===============*/

const char* Form::GradeTooHighException::what( void ) const throw() {
	return ("\033[31mGrade too high.\033[0m");
}

const char* Form::GradeTooLowException::what( void ) const throw() {
	return ("\033[31mGrade too low.\033[0m");
}

