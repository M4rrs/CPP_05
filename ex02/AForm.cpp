#include "Form.hpp"

/*=============== CONSTRUCTOR ===============*/

Form::Form( void ) : _name("Unknown"), _signGrade(75), _execGrade(1) {
	_signed = false;
	std::cout << "Default Form " + _name + " constructed." << std::endl;
}

Form::Form( int sign, int exec ) : _name("Unknown"), _signGrade(setGrade(sign)), _execGrade(setGrade(exec)) {
	_signed = false;
	std::cout << "Grade instantiated Form " + _name + " constructed." << std::endl;
}

Form::Form( std::string name, int sign, int exec ) : _name(name), _signGrade(setGrade(sign)), _execGrade(setGrade(exec)){
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
	out << insert->getName() + ": Grade to sign[\033[32m" << insert->getSign()
		<< "\033[0m] Grade to execute[\033[32m" << insert->getExec() << "\033[0m]\n"
		<< "Current form status[\033[32m" << insert->getStatus() << "\033[0m]"
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
		if (grade < 1)
			throw Form::GradeTooHighException();
		else if (grade > 150)
			throw Form::GradeTooLowException();
	}
	catch (Form::GradeTooHighException &except) {
		std::cout << except.what() << " Grade set to maximum (1)\033[0m"
			 << std::endl;
		return(1);
	}
	catch (Form::GradeTooLowException &except) {
		std::cout << except.what() << " Grade set to minimum (150)\033[0m"
			 << std::endl;
		return(150);
	}
	return(grade);
}

void Form::beSigned( Bureaucrat *b ) {
	try {
		if (_signed)
			throw Form::FormSigned();
		else if (b->getGrade() <= _signGrade) {
			_signed = true;
			b->signForm(*this);
		}
		else if ( b->getGrade() > _signGrade ) {
			throw Form::GradeTooLowException();
		}
	}
	catch (Form::GradeTooLowException &except) {
		std::cout << except.what() << " Minimum grade to sign this Form is ("
				<< _signGrade << ")\033[0m"
				<< std::endl;
		b->signForm(*this);
	}
	catch (Form::FormSigned &except) {
		std::cout << except.what() << std::endl;
	}
}


/*=============== 	EXCEPTION  ===============*/

const char* Form::GradeTooHighException::what( void ) const throw() {
	return ("\033[31mGrade too high.");
}

const char* Form::GradeTooLowException::what( void ) const throw() {
	return ("\033[31mGrade too low.");
}

const char* Form::FormSigned::what( void ) const throw() {
	return ("\033[31mThis form has already been signed by another Bureaucrat.\033[0m");
}
