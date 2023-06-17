#include "AForm.hpp"

/*=============== CONSTRUCTOR ===============*/

AForm::AForm( void ) : _name("Unknown"), _signGrade(75), _execGrade(1) {
	_signed = false;
	_executed = false;
	std::cout << "Default Form " + _name + " constructed." << std::endl;
}

AForm::AForm( int sign, int exec ) : _name("Unknown"), _signGrade(setGrade(sign)), _execGrade(setGrade(exec)) {
	_signed = false;
	_executed = false;
	std::cout << "Grade instantiated Form " + _name + " constructed." << std::endl;
}

AForm::AForm( std::string name, int sign, int exec ) : _name(name), _signGrade(setGrade(sign)), _execGrade(setGrade(exec)){
	_signed = false;
	_executed = false;
	std::cout << "Form " + _name + " constructed." << std::endl;
}

/*=============== DESTRUCTOR ===============*/

AForm::~AForm( void ) {
	std::cout << "Form " + _name + " destructed." << std::endl;
}

/*=============== COPY CONSTRUCTOR ===============*/

AForm::AForm( const AForm &copy ) : _name(copy._name), _signGrade(copy._signGrade), _execGrade(copy._execGrade) {
	*this = copy;
	std::cout << "Form " + this->_name + " cloned." << std::endl;
}

/*=============== OVERLOADED OPERATOR ===============*/

AForm &AForm::operator=( const AForm &assign ) {

	this->_signed = assign._signed;
	this->_executed = assign._executed;
	return (*this);
}

std::ostream &operator<<( std::ostream &out, AForm *insert ) {
	out << insert->getName() + ": Grade to sign[\033[32m" << insert->getSign()
		<< "\033[0m] Grade to execute[\033[32m" << insert->getExec() << "\033[0m]\n"
		<< "Current form status[\033[32m" << insert->getStatus() << "\033[0m]\n"
		<< "Execution status[\033[32m" << insert->getExecStatus() << "\033[0m]\n"
		<< std::endl;
	return (out);
}

/*=============== PUBLIC  ===============*/

std::string AForm::getName( void ) const {
	return (_name);
}

int	AForm::getSign( void ) const {
	return(_signGrade);
}

int	AForm::getExec( void ) const {
	return(_execGrade);
}

bool	AForm::getStatus( void ) const {
	return(_signed);
}

bool	AForm::getExecStatus( void ) const {
	return(_executed);
}

int AForm::setGrade( int grade ) {
	try {
		if (grade < 1)
			throw AForm::GradeTooHighException();
		else if (grade > 150)
			throw AForm::GradeTooLowException();
	}
	catch (AForm::GradeTooHighException &except) {
		std::cout << except.what() << " Grade set to maximum (1)\033[0m"
			 << std::endl;
		return(1);
	}
	catch (AForm::GradeTooLowException &except) {
		std::cout << except.what() << " Grade set to minimum (150)\033[0m"
			 << std::endl;
		return(150);
	}
	return(grade);
}

void AForm::beSigned( Bureaucrat *b ) {
	try {
		if (_signed)
			throw AForm::FormSigned();
		else if (b->getGrade() <= _signGrade) {
			_signed = true;
			b->signForm(*this);
		}
		else if ( b->getGrade() > _signGrade ) {
			throw AForm::GradeTooLowException();
		}
	}
	catch (AForm::GradeTooLowException &except) {
		std::cout << except.what() << " Minimum grade to sign this Form is ("
				<< _signGrade << ")\033[0m"
				<< std::endl;
		b->signForm(*this);
	}
	catch (AForm::FormSigned &except) {
		std::cout << except.what() << std::endl;
	}
}


/*=============== 	EXCEPTION  ===============*/

const char* AForm::GradeTooHighException::what( void ) const throw() {
	return ("\033[31mGrade too high.");
}

const char* AForm::GradeTooLowException::what( void ) const throw() {
	return ("\033[31mGrade too low.");
}

const char* AForm::FormSigned::what( void ) const throw() {
	return ("\033[31mThis form has already been signed by another Bureaucrat.\033[0m");
}
