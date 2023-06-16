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
		std::cout << except.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &except) {
		_grade = 150;
		std::cout << except.what() << std::endl;
	}
}

void Bureaucrat::promote( int promotion ) {
	setGrade(this->_grade - promotion);
	std::cout << "\033[33mCongratulations " + this->_name + ", you have been promoted to grade "
			<< this->_grade << "\033[0m"
			<< std::endl;
}

void Bureaucrat::demote( int demotion ) {
	setGrade(this->_grade + demotion);
	std::cout << "\033[33mUnfortunately " + this->_name + ", you have been demoted to grade "
			<< this->_grade << "\033[0m"
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
/*=============== 	EXCEPTION  ===============*/

const char* Bureaucrat::GradeTooHighException::what( void ) const throw() {
	return ("\033[31mGrade too high. Grade set to maximum (1).\033[0m");
}

const char* Bureaucrat::GradeTooLowException::what( void ) const throw() {
	return ("\033[31mGrade too low. Grade set to minimum (150)\033[0m");
}

