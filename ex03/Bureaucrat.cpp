#include "Bureaucrat.hpp"

/*=============== CONSTRUCTOR ===============*/

Bureaucrat::Bureaucrat( void ) : _name("Nameless"), _grade(150) {
	std::cout << "Default Bureaucrat " + _name + " constructed." << std::endl;
}

Bureaucrat::Bureaucrat( int grade ) : _name("Nameless") {
	setGrade(grade);
	std::cout << "Grade instantiated Bureaucrat " + _name + " constructed." << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	setGrade(grade);
	std::cout << "Bureaucrat " + _name + " constructed." << std::endl;
}

/*=============== DESTRUCTOR ===============*/
Bureaucrat::~Bureaucrat( void ) {
	std::cout << "Bureaucrat " + _name + " destructed." << std::endl;
}

/*=============== COPY CONSTRUCTOR ===============*/

Bureaucrat::Bureaucrat( const Bureaucrat &copy ) : _name(copy._name) {
	*this = copy;
	std::cout << "Bureaucrat " + this->_name + " cloned." << std::endl;
}

/*=============== OVERLOADED OPERATOR ===============*/

Bureaucrat &Bureaucrat::operator=( const Bureaucrat &assign ) {

	this->_grade = assign._grade;

	return (*this);
}

std::ostream &operator<<( std::ostream &out, Bureaucrat *insert ) {
	out << insert->getName() + ", bureaucrat grade " << insert->getGrade()
		<< std::endl;
	return (out);
}

/*=============== PUBLIC  ===============*/

std::string Bureaucrat::getName( void ) const {
	return (_name);
}

int	Bureaucrat::getGrade( void ) const {
	return(_grade);
}

void Bureaucrat::setGrade( int grade ) {
	try {
		if (grade >= 1 && grade <= 150)
			this->_grade = grade;
		else if (grade < 1)
			throw Bureaucrat::GradeTooHighException();
		else if (grade > 150)
			throw Bureaucrat::GradeTooLowException();
	}
	catch (Bureaucrat::GradeTooHighException &except) {
		_grade = 1;
		std::cout << RED << except.what() 
				<< " Grade set to maximum (1)"
				<< RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &except) {
		_grade = 150;
		std::cout << RED << except.what()
				<< " Grade set to maximum (1)"
				<< RESET << std::endl;
	}
}

void Bureaucrat::promote( int promotion ) {
	setGrade(this->_grade - promotion);
	std::cout << YELLOW << "Congratulations " + this->_name + ", you have been promoted to grade "
			<< this->_grade << RESET
			<< std::endl;
}

void Bureaucrat::demote( int demotion ) {
	setGrade(this->_grade + demotion);
	std::cout << YELLOW << "Unfortunately " + this->_name + ", you have been demoted to grade "
			<< this->_grade << RESET
			<< std::endl;
}

void Bureaucrat::signForm( AForm &f ) {
	if (f.getStatus()) {
		std::cout << _name << " signed " << f.getName() << "."
				<< std::endl;
	}
	else if (!f.getStatus()) {
		std::cout << _name << " could not sign " << f.getName()
				<< " because their grade is too low." << std::endl;
	}
}

void Bureaucrat::executeForm( AForm const &f ) {
	try {
		if (!f.getStatus()) {
			std::cout << RED << f.getName();
			throw Bureaucrat::UnsignedForm();
		}
		else if (getGrade() > f.getExec()) {
			throw Bureaucrat::GradeTooLowException();
		}
		else {
			std::cout << _name << " executed " << f.getName() << std::endl;
			f.execute(*this);
		}
	}
	catch (Bureaucrat::UnsignedForm &except) {
		std::cout << except.what() << RESET << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &except) {
		std::cout << RED << except.what()
				<< " Required grade to execute this form is ("
				<< f.getExec() << ")" << RESET
				<< std::endl;
	}
	catch (Bureaucrat::ExecGradeLow &except) {
		std::cout << RED << except.what() 
				<< " Required grade to execute this form is ("
				<< f.getExec() << ")" << RESET
				<< std::endl;
	}

}
/*=============== 	EXCEPTION  ===============*/

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("Grade too high.");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("Grade too low.");
}

const char* Bureaucrat::UnsignedForm::what( void ) const throw() {
	return (". Form status unsigned.");
}

const char* Bureaucrat::ExecGradeLow::what( void ) const throw() {
	return ("Execution grade too low.");
}
